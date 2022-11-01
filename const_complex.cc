#include <cmath>
#include <complex>
#include <iostream>

int main(int argc, char *argv[]) {
    const std::complex<float> cc{0.0, 0.0};
    std::complex<float> c{0.0, 0.0};

    //this will fail to compile with nvc++ when c++ standard >= 14
    //gcc, clang and nvcc can compile it since c++11
    std::cout << std::hypot(cc.real(), cc.imag()) << std::endl;

    //compiles
    std::cout << std::hypot(c.real(), c.imag()) << std::endl;
}