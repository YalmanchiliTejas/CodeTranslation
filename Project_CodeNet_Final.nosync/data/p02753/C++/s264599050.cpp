
#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>
#include <cmath>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N;
std::string S;

int main()
{
    using std::endl;
    in.sync_with_stdio(false);
    out.sync_with_stdio(false);
    in.tie(nullptr);
    out.tie(nullptr);

    in >> S;
    if (S[0] != S[1] || S[1] != S[2]) {
        out << "Yes" << endl;
    }
    else {
        out << "No" << endl;
    }

    return 0;
}
#endif
