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

    std::vector<int64_t> A;
    for (size_t i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;
        A.push_back(t);
    }

    if (N % 2 == 0) {
        for (int64_t i = N; i >= 2; i-= 2) {
            std::cout << A[i-1] << " ";
        }
        for (int64_t i = 1; i <= N; i+= 2) {
            std::cout << A[i-1] << " ";
        }
    }
    else {
        for (int64_t i = N; i >= 1; i-= 2) {
            std::cout << A[i-1] << " ";
        }
        for (int64_t i = 2; i <= N-1; i+= 2) {
            std::cout << A[i-1] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
