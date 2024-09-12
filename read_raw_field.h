// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2018 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef DIRECTIONAL_READ_RAW_FIELD_H
#define DIRECTIONAL_READ_RAW_FIELD_H
#include <cmath>
#include <Eigen/Core>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>


namespace directional
{
    bool IGL_INLINE read_TXT(const std::string& fileName,
        int& numF,
        std::vector<Eigen::VectorXd>& rawField)
    {
        try
        {
            std::ifstream f(fileName);
            if (!f.is_open()) {
                return false;
            }
            char buf[1024];
            numF = 0;
            while (f.getline(buf, sizeof(buf)))   // 读入文件行于buf
            {
                std::stringstream line(buf);         // 将line改为字符串

                //int f1, f2, f3;
                //line >> f1 >> f2 >> f3;
                //F2F[F2N[Eigen::Vector3i(f1, f2, f3)]] = cnt; // F2F[0] denotes 
                //cnt++;

                double x1, x2, x3, x4, x5, x6;
                line >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
                Eigen::VectorXd X(12);
                X << x1, x2, x3, x4, x5, x6, -x1, -x2, -x3, -x4, -x5, -x6;
                rawField.emplace_back(X);
                numF++;
            }

            f.close();
            return f.good();
        }
        catch (std::exception e)
        {
            return false;
        }
    }

  // Reads a raw field from a file
  // Inputs:
  //   fileName: The to be loaded file.
  // Outputs:
  //   N: The degree of the field
  //   rawField: the read field in raw #F by 3*N xyzxyz format
  // Return:
  //   Whether or not the file was read successfully
  bool IGL_INLINE read_raw_field(const std::string &fileName,
                                 int& N,
                                 Eigen::MatrixXd& rawField)
  {
      std::vector<Eigen::VectorXd> raw;
      int numF;
      N = 4;
      read_TXT(fileName, numF, raw);

      rawField.conservativeResize(numF, 3 * N);

      for (int i = 0; i < rawField.rows(); i++)
          for (int j = 0; j < rawField.cols(); j++)
              rawField(i, j) = raw[i](j);
      return true;
  }
}

#endif
