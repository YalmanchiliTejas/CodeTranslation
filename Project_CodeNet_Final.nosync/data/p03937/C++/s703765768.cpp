#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int h, w;
    cin >> h >> w;
    int sm = 0;
    for (int y = 0; y < h; y++) {
        string s;
        cin >> s;
        for (auto c: s) {
            if (c == '#') sm++;
        }
    }
    if (sm == h+w-1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
