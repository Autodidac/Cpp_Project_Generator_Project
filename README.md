# Cpp_Project_Generator_Project
### The names are pretty specific.. this is a simple C++ project capable of generating a simple C++ project.. only after compilation so CMake Generates a VC Studio Project

### The purpose of this is that it can be used to rapidly generate projects with crossplatform/cross editor setups without having to create this in the first place... it also automates project generation, and is also intended to be like "Run Game" for unity, except in the Almond Engine

### This is intended to be the core project "script compiler/project generator" with-in the Almond Shell and Almond Engine open source libraries.


#### using clang to build and run

```c++

clang++ -std=c++20 -o projgen.exe src/main.cpp
./projgen MyProject
cd MyProject
mkdir build && cd build
cmake .. && cmake --build .

```



#### using cmake to build and run

```c++

mkdir build && cd build
cmake .. && cmake --build .
./projgen MyProject
cd MyProject
mkdir build && cd build
cmake .. && cmake --build .

```
