#include <iostream>
#include "Point2D.h"

int main() {
    std::cout << std::boolalpha; // Mostrar true/false en lugar de 1/0

    Point2D a(0, 0);
    Point2D b(1, 1);
    std::cout << "a = " << a << "; b = " << b << std::endl;
    std::cout << "d(a,b) = " << Point2D::distance(a, b) << std::endl;
    std::cout << "a==b --> " << (a == b) << std::endl;
    std::cout << "a!=b --> " << (a != b) << std::endl;

    std::cout << std::endl;
    a = b;
    std::cout << "a = " << a << "; b = " << b << std::endl;
    std::cout << "d(a,b) = " << Point2D::distance(a, b) << std::endl;
    std::cout << "a==b --> " << (a == b) << std::endl;
    std::cout << "a!=b --> " << (a != b) << std::endl;

    return 0;
}
