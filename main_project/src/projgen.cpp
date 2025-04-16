#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void write(const fs::path& path, const std::string& content) {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "Failed to write: " << path << "\n";
        return;
    }
    file << content;
    std::cout << "[+] Created " << path << "\n";
}

int main() {
    const fs::path root = "generated_project";
    const fs::path src = root / "src";
    const fs::path include = root / "include";

    fs::create_directories(src);
    fs::create_directories(include);

    // CMakeLists.txt
    write(root / "CMakeLists.txt", R"(cmake_minimum_required(VERSION 3.20)
project(MyCpp20Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
include_directories(include)
add_executable(MyCpp20App ${SOURCES})
)");

    // main.cpp
    write(src / "main.cpp", R"(#include <iostream>
int main() {
    std::cout << "Project created.\n";
    return 0;
}
)");

    // mylib.hpp
    write(include / "mylib.hpp", R"(#pragma once
namespace mylib {
    void placeholder();
}
)");

    // mylib.cpp
    write(src / "mylib.cpp", R"(#include "mylib.hpp"
namespace mylib {
    void placeholder() { /* TODO */ }
}
)");

    std::cout << "\n[✓] Project generated in: " << fs::absolute(root) << "\n";
}
