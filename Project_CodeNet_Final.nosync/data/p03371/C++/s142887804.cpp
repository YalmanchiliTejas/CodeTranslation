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

using namespace std;

int main()
{
    int64_t A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;

    int64_t p, q, r;
    p = X*A + Y*B;

    if (X > Y) {
        q = Y * C*2 + (X-Y)*A;
        r = X * C*2;
    }
    else {
        q = X * C*2 + (Y-X)*B;
        r = Y * C*2;
    }

    auto s = std::min(std::min(p,q), r);
    cout << s << endl;

    return 0;
}
