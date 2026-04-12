#if !defined(__clang__) && defined(__GNUC__)
#include <bits/stdc++.h>
#else
#include <cstdlib>
#include <climits>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <complex>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#endif //  !defined(__clang__) && defined(__GNUG__)
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/math/common_factor_rt.hpp>

using namespace std;

int main()
{
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> X;
    for (decltype(N) i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;
        X.push_back(t);
    }

    auto Y = X;
    std::sort(std::begin(Y), std::end(Y));

    for (int64_t i = 0; i < N; ++i) {
        if (X[i] < Y[N/2]) {
            std::cout << Y[N/2] << std::endl;
        }
        else {
            std::cout << Y[N/2-1] << std::endl;
        }
    }

    return 0;
}
