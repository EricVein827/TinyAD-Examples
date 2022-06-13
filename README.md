# TinyAD-Examples

This repository contains **code examples** for **automatic differentiation with TinyAD**. Please see the [**README in the main TinyAD repository**](https://gitlab.vci.rwth-aachen.de:9000/pschmidt/TinyAD) for an overview.

The TinyAD examples have been tested on Linux and require:
* A C++17 compiler
* CMake >= 3.9 (e.g. `sudo apt-get install cmake`)
* GLFW build dependencies (e.g. `sudo apt-get build-dep glfw3`)
* OpenGL >= 4.5 (e.g. `sudo apt-get install libgl1-mesa-dev mesa-utils`)

Build the examples via:
```
mkdir build
cd build
cmake ..
make 
```

Note that this repository comes with quite a few dependencies as submodules. However, [TinyAD](https://gitlab.vci.rwth-aachen.de:9000/pschmidt/TinyAD) itself is a lightweight header-only library that only depends on Eigen and has been tested on Linux, Windows, and Mac.
