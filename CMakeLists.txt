cmake_minimum_required(VERSION 3.20)

option(CUDA_EIGEN_KERNEL "Call eigen from withing a cuda kernel" ON)

project(compile_error_demo CXX)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(compile_features INTERFACE)
target_compile_features(compile_features INTERFACE cxx_std_17)

add_executable(${PROJECT_NAME} eigen_nvhpc.cc)

target_compile_options(${PROJECT_NAME} PRIVATE -O0 -cuda -gpu=managed -stdpar)
target_link_options(${PROJECT_NAME} PRIVATE -cuda -gpu=managed -stdpar)


if(CUDA_EIGEN_KERNEL)
    target_compile_definitions(${PROJECT_NAME} PRIVATE CUDA_EIGEN_KERNEL)
endif(CUDA_EIGEN_KERNEL)

target_link_libraries(${PROJECT_NAME} Eigen3::Eigen compile_features)