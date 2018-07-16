#ifndef TEMPLATABLE_CONSTEXPRSTRING_HPP
#define TEMPLATABLE_CONSTEXPRSTRING_HPP

/*
 * Inspired by https://stackoverflow.com/questions/1826464/c-style-strings-as-template-arguments
 * This following class can be used as a template argument
 * Concatenation with 2 constexpr string is also allowed.
 */

#include <iostream>
#include <string>

template <char... Chars>
struct ConstexprStr
{
    static constexpr auto LENGTH = sizeof...(Chars);

    constexpr char at(std::size_t idx) const
    {
        constexpr char NAME[] = { Chars..., '\0' };
        return NAME[idx];
    }

    constexpr char operator[](std::size_t idx) const
    {
        constexpr char NAME[] = { Chars..., '\0' };
        return NAME[idx];
    }

    std::string to_string() const
    {
        return { Chars..., '\0' };
    }

    friend std::ostream& operator<< (std::ostream& os, ConstexprStr)
    {
        static constexpr char NAME[] = { Chars..., '\0' };
        return os.write(NAME, sizeof...(Chars) + 1);
    }

    constexpr friend ConstexprStr<Chars...> operator+(ConstexprStr<Chars...>, ConstexprStr<'\0'>)
    {
        return {};
    }

    template <char... OtherChars>
    constexpr friend ConstexprStr<Chars..., OtherChars...> operator+(ConstexprStr<Chars...>, ConstexprStr<OtherChars...>)
    {
        return {};
    }
};

template <char... Chars>
std::string to_string(const ConstexprStr<Chars...>& str)
{
    return str.to_string();
}

static_assert(sizeof(ConstexprStr<1,2,3,4,5>{}) == 1, "This class should always be empty class");
static_assert(ConstexprStr<1,2,3,4,5>{}.at(1) == 2, "at() must be constexpr");
static_assert(ConstexprStr<1,2,3,4,5>{}[2] == 3, "operator[] must be constexpr");

template<std::size_t N>
constexpr char at(const char (&str)[N], std::size_t idx)
{
    return idx < N ? str[idx] : '\0';
}

#define constexprStr(s)\
decltype(\
    ConstexprStr<at(s,0)>{}+\
    ConstexprStr<at(s,1)>{}+\
    ConstexprStr<at(s,2)>{}+\
    ConstexprStr<at(s,3)>{}+\
    ConstexprStr<at(s,4)>{}+\
    ConstexprStr<at(s,5)>{}+\
    ConstexprStr<at(s,6)>{}+\
    ConstexprStr<at(s,7)>{}+\
    ConstexprStr<at(s,8)>{}+\
    ConstexprStr<at(s,9)>{}+\
    ConstexprStr<at(s,10)>{}+\
    ConstexprStr<at(s,11)>{}+\
    ConstexprStr<at(s,12)>{}+\
    ConstexprStr<at(s,13)>{}+\
    ConstexprStr<at(s,14)>{}+\
    ConstexprStr<at(s,15)>{}+\
    ConstexprStr<at(s,16)>{}+\
    ConstexprStr<at(s,17)>{}+\
    ConstexprStr<at(s,18)>{}+\
    ConstexprStr<at(s,19)>{}+\
    ConstexprStr<at(s,20)>{}+\
    ConstexprStr<at(s,21)>{}+\
    ConstexprStr<at(s,22)>{}+\
    ConstexprStr<at(s,23)>{}+\
    ConstexprStr<at(s,24)>{}+\
    ConstexprStr<at(s,25)>{}+\
    ConstexprStr<at(s,26)>{}+\
    ConstexprStr<at(s,27)>{}+\
    ConstexprStr<at(s,28)>{}+\
    ConstexprStr<at(s,29)>{}+\
    ConstexprStr<at(s,30)>{}+\
    ConstexprStr<at(s,31)>{}+\
    ConstexprStr<at(s,32)>{}+\
    ConstexprStr<at(s,33)>{}+\
    ConstexprStr<at(s,34)>{}+\
    ConstexprStr<at(s,35)>{}+\
    ConstexprStr<at(s,36)>{}+\
    ConstexprStr<at(s,37)>{}+\
    ConstexprStr<at(s,38)>{}+\
    ConstexprStr<at(s,39)>{}+\
    ConstexprStr<at(s,40)>{}+\
    ConstexprStr<at(s,41)>{}+\
    ConstexprStr<at(s,42)>{}+\
    ConstexprStr<at(s,43)>{}+\
    ConstexprStr<at(s,44)>{}+\
    ConstexprStr<at(s,45)>{}+\
    ConstexprStr<at(s,46)>{}+\
    ConstexprStr<at(s,47)>{}+\
    ConstexprStr<at(s,48)>{}+\
    ConstexprStr<at(s,49)>{}+\
    ConstexprStr<at(s,50)>{}+\
    ConstexprStr<at(s,51)>{}+\
    ConstexprStr<at(s,52)>{}+\
    ConstexprStr<at(s,53)>{}+\
    ConstexprStr<at(s,54)>{}+\
    ConstexprStr<at(s,55)>{}+\
    ConstexprStr<at(s,56)>{}+\
    ConstexprStr<at(s,57)>{}+\
    ConstexprStr<at(s,58)>{}+\
    ConstexprStr<at(s,59)>{}+\
    ConstexprStr<at(s,60)>{}+\
    ConstexprStr<at(s,61)>{}+\
    ConstexprStr<at(s,62)>{}+\
    ConstexprStr<at(s,63)>{} \
)

#endif // TEMPLATABLE_CONSTEXPRSTRING_HPP
