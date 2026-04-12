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


bool solve(char p2, char p1, auto& S)
{
    char initP2 = p2; // 最後の仮定
    char initP1 = p1; // 先頭の仮定

    std::string ans;
    for (size_t i = 0; i < S.size(); ++i) {
        auto c = S[i];
        char next;
        if (p2 == 'W' && p1 == 'W') {
            if (c == 'o') {
                next = 'S';
            }
            else {
                next = 'W';
            }
        }
        else if (p2 == 'S' && p1 == 'W') {
            if (c == 'o') {
                next = 'W';
            }
            else {
                next = 'S';
            }
        }
        else if (p2 == 'W' && p1 == 'S') {
            if (c == 'o') {
                next = 'W';
            }
            else {
                next = 'S';
            }
        }
        else {
            // p2 == 'S' && p1 == 'S'
            if (c == 'o') {
                next = 'S';
            }
            else {
                next = 'W';
            }
        }
        ans += p1;

        p2 = p1;
        p1 = next;
    }

    if (initP2 == ans[ans.size()-1] &&
        initP1 == p1)
    {
        std::cout << ans << std::endl;
        return true;
    }
    return false;
}



int main()
{
    int64_t N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    if (solve('W', 'S', S)) {
        return 0;
    }
    if (solve('S', 'S', S)) {
        return 0;
    }
    if (solve('W', 'W', S)) {
        return 0;
    }
    if (solve('S', 'W', S)) {
        return 0;
    }

    std::cout << "-1" << std::endl;

    return 0;
}
