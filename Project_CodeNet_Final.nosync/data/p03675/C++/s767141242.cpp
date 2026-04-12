#include <cstdlib>
#include <climits>
#include <iostream>
#include <sstream>
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

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>

using namespace std;

int main()
{
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> a;
    for (int64_t i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;
        a.push_back(t);
    }

    if (N % 2 == 0) {
        // 偶数
        for (int64_t i = N - 1; i > 0; i -= 2) {
            std::cout << a[i] << " ";
        }
        for (int64_t i = 0; i < N; i += 2) {
            std::cout << a[i] << " ";
        }
    }
    else {
        // 奇数
        for (int64_t i = N - 1; i >= 0; i -= 2) {
            std::cout << a[i] << " ";
        }
        for (int64_t i =1; i < N; i += 2) {
            std::cout << a[i] << " ";
        }
    }

    return 0;
}
