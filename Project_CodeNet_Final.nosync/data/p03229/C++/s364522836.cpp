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

    std::sort(std::begin(A), std::end(A));

    auto B = A;
    std::reverse(std::begin(B), std::end(B));

    std::vector<int64_t> s, ss;
    if (N % 2 == 1) {
        s.push_back(A[N/2]);
        ss.push_back(B[N/2]);

        for (int64_t i = 0; i < N - 1; ++i) {
            if (i % 2 == 1) {
                s.push_back(A[i/2]);
                ss.push_back(B[i/2]);
            }
            else {
                s.push_back(B[i/2]);
                ss.push_back(A[i/2]);
            }
        }
    }
    else {
        s.push_back(A[N/2 - 1]);
        ss.push_back(B[N/2 - 1]);
        for (int64_t i = 0; i < N - 1; ++i) {
            if (i % 2 == 1) {
                s.push_back(A[i/2]);
                ss.push_back(B[i/2]);
            }
            else {
                s.push_back(B[i/2]);
                ss.push_back(A[i/2]);
            }
        }

    }

    int64_t p, q;
    p = q = 0;
    for (size_t i = 1; i < N; ++i) {
        p += std::abs(s[i] - s[i-1]);
        q += std::abs(ss[i] - ss[i-1]);
    }

    std::cout << std::max(p, q) << std::endl;

    return 0;
}
