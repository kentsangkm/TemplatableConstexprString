#include "ConstexprString.hpp"

template<typename NAME>
struct Foo
{
    friend std::ostream& operator<< (std::ostream& os, Foo)
    {
        return os << NAME{};
    }
};

int main(int argc, char *argv[])
{
    // https://stackoverflow.com/questions/1826464/c-style-strings-as-template-arguments
    constexprStr("This is a very long text. You can only store the first 64 bytes string in one marco call. ") longStr1;
    constexprStr("If you wanna have a longer string, you can just do a decltype(str + str)") longStr2;
        
    std::cout << longStr1.to_string() << std::endl;
    std::cout << std::to_string(longStr2) << std::endl;
    std::cout << longStr1 << std::endl;
    std::cout << longStr2 << std::endl;
    std::cout << (longStr1 + longStr2) << std::endl;
    
    std::cout << Foo<constexprStr("bar")>{} << std::endl;
}
