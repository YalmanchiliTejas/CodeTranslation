#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

int main() {
    string s;
    cin >> s;
    bool ok = false;
    for (int j = 0; j < s.size()-1; ++j) {
        if (s[j] == 'A' && s[j+1] == 'C') ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
