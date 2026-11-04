#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle() : Shape("red"), center(Point2D(0,0)), radius(1.0) {}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center) {
    if (radius < 0) {
        throw std::invalid_argument("El radio no puede ser negativo");
    }
    this->radius = radius;
}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r < 0) {
        throw std::invalid_argument("El radio no puede ser negativo");
    }
    radius = r;
}

double Circle::area() const {
    return 3.141592 * std::pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * 3.141592 * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "[Circle: color = " << c.color << "; center = " << c.center << "; radius = " << c.radius << "]";
    return out;
}
