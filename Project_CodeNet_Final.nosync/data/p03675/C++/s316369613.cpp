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
#include <boost/math/common_factor_rt.hpp>  // https://boostjp.github.io/tips/math.html
#include <boost/dynamic_bitset.hpp>  // https://boostjp.github.io/tips/dynamic_bitset.html

constexpr int64_t DIV1097 = 1000000007LL;

using namespace std;

int main()
{
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> A;
    for (decltype(N) i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;
        A.push_back(t);
    }

    std::vector<int64_t> B;

    for (int64_t i = N-1; i >= 0; i -=2) {
        B.push_back(A[i]);
    }
    if (N % 2 == 0) {
        // 偶数
        for (int64_t i = 0; i < N; i += 2) {
            B.push_back(A[i]);
        }
    }
    else {
        // 奇数
        for (int64_t i = 1; i < N; i += 2) {
            B.push_back(A[i]);
        }
    }

    for (auto& b: B) {
        std::cout << b << " ";
    }
    std::cout << std::endl;

    return 0;
}
