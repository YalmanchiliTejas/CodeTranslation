#ifndef AC_ABC_LIB_HPP
#define AC_ABC_LIB_HPP

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> sys_args(int argc, char **argv) {
    std::vector<std::string> args;

    for (int i = 1; i < argc; ++i)
        args.emplace_back(argv[i]);

    return args;
}

template<typename T>
void print(const T& vs) {
    std::cout << "[ ";

    for (auto&& v : vs)
        std::cout << v << " ";

    std::cout << "]" << std::endl;
}

std::vector<int> get_n_vector(void) {
    size_t n;
    std::cin >> n;

    std::vector<int> hs;
    hs.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        int h;
        std::cin >> h;
        hs.emplace_back(h);
    }

    return hs;
}

#endif  // AC_ABC_LIB_HPP
using namespace std;

int main(int argc, char **argv) {
    auto hs = get_n_vector();
    int hotels = 0, maxh = 0;

    vector<int> maxlist;
    for (auto&& h : hs) {
        if (maxh < h)
            maxh = h;
        maxlist.emplace_back(maxh);
    }

    for (size_t i = 0; i < maxlist.size(); ++i) {
        if (maxlist[i] <= hs[i])
            hotels++;
    }

    cout << hotels << endl;

    return 0;
}