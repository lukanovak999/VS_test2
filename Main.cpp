#include <iostream>

// test code
class Vector
{
private:
    int x = 0, y = 0, z = 0;
public:
    Vector() = default;
    Vector(int x, int y, int z) : x(x), y(y), z(z) { std::cout << "Created vec" << std::endl; }
    Vector(const Vector& orig) : x(orig.x), y(orig.y), z(orig.z) { std::cout << "Copy constructor" << std::endl; }
    Vector& operator=(const Vector& orig)
    {
        x = orig.x;
        y = orig.y;
        z = orig.z;
        std::cout << "Copy assignment" << std::endl;
        return *this;
    }
    ~Vector() { std::cout << "Destroyed vector" << std::endl; }
    void print_vec(std::ostream& stream)
    {
        stream << "x: " << x << " y: " << y << " z: " << z;
        std::cout << std::endl;
    }
};

int main()
{
    Vector vec(5, 6, 7);
    vec.print_vec(std::cout);

    Vector vec2;
    vec2.print_vec(std::cout);

    Vector vec3 = vec;
    vec3.print_vec(std::cout);

    vec3 = vec2;
    vec3.print_vec(std::cout);

    Vector vec4(vec);
    vec4.print_vec(std::cout);
}