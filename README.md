## NVCC
Compiles without issues (when file renamed with .cu ext)

## NVHPC 22.7
Compile error only when we set ```-DCUDA_EIGEN_KERNEL=ON```

```
/opt/nvidia/hpc_sdk/Linux_x86_64/22.7/compilers/bin/nvc++ -DCUDA_EIGEN_KERNEL -isystem /usr/local/include/eigen3 -O0 -cuda -gpu=managed -stdpar -MD -MT CMakeFiles/compile_error_demo.dir/eigen_nvhpc.cc.o -MF CMakeFiles/compile_error_demo.dir/eigen_nvhpc.cc.o.d -o CMakeFiles/compile_error_demo.dir/eigen_nvhpc.cc.o -c /home/esseivaj/bld4/devel/eigen_nvhpc/eigen_nvhpc.cc
nvvmCompileProgram error 9: NVVM_ERROR_COMPILATION.
Error: /tmp/pgaccgOgCs34z2Lkc.gpu (24636, 47): parse use of undefined value '@_ZN5Eigen8internal4pmaxIdEET_RKS2_S4_'
NVC++-F-0155-Compiler failed to translate accelerator region (see -Minfo messages): Device compiler exited with error status code (/home/esseivaj/bld4/devel/eigen_nvhpc/eigen_nvhpc.cc: 1)
NVC++/x86-64 Linux 22.7-0: compilation aborted
```

## NVHPC 22.9

Compile error regardless of ```-DCUDA_EIGEN_KERNEL``` value with ```C++ standard``` >= 14. With c++11, we get the same error as nvhpc 22.7, 

```
/opt/nvidia/hpc_sdk/Linux_x86_64/22.9/compilers/bin/nvc++ -DCUDA_EIGEN_KERNEL -isystem /usr/local/include/eigen3 -O0 -cuda -gpu=managed -stdpar --c++17 --gnu_extensions -MD -MT CMakeFiles/compile_error_demo.dir/eigen_nvhpc.cc.o -MF CMakeFiles/compile_error_demo.dir/eigen_nvhpc.cc.o.d -o CMakeFiles/compile_error_demo.dir/eigen_nvhpc.cc.o -c /home/esseivaj/bld4/devel/eigen_nvhpc/eigen_nvhpc.cc
"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1535: error: no instance of overloaded function "std::complex<float>::real" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<float>
    return ::hypotf(x.real(), x.imag());
                      ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1535: error: no instance of overloaded function "std::complex<float>::imag" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<float>
    return ::hypotf(x.real(), x.imag());
                                ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1540: error: no instance of overloaded function "std::complex<double>::real" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<double>
    return ::hypot(x.real(), x.imag());
                     ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1540: error: no instance of overloaded function "std::complex<double>::imag" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<double>
    return ::hypot(x.real(), x.imag());
                               ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1564: error: no instance of overloaded function "std::complex<float>::real" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<float>
    float com = ::expf(x.real());
                         ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1565: error: no instance of overloaded function "std::complex<float>::imag" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<float>
    float res_real = com * ::cosf(x.imag());
                                    ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1566: error: no instance of overloaded function "std::complex<float>::imag" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<float>
    float res_imag = com * ::sinf(x.imag());
                                    ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1572: error: no instance of overloaded function "std::complex<double>::real" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<double>
    double com = ::exp(x.real());
                         ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1573: error: no instance of overloaded function "std::complex<double>::imag" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<double>
    double res_real = com * ::cos(x.imag());
                                    ^

"/usr/local/include/eigen3/Eigen/src/Core/MathFunctions.h", line 1574: error: no instance of overloaded function "std::complex<double>::imag" matches the argument list and object (the object has type qualifiers that prevent a match)
            object type is: const std::complex<double>
    double res_imag = com * ::sin(x.imag());
                                    ^

10 errors detected in the compilation of "/home/esseivaj/bld4/devel/eigen_nvhpc/eigen_nvhpc.cc".
```