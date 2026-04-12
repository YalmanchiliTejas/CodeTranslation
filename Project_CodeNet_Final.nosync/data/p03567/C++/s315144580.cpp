#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define ll long long
#define forn(i, n) for (ll i = 0; i < (ll) n; ++i)
#define sz(a) static_cast<int>(a.size())

char buff[(int) 2e6 + 17];
const ll inf = (ll) 1e9 + 7ll;

const int maxn = (int) 2e5 + 17;

int n;
string s;
int ps[maxn];

bool read() {
    if (scanf("%s", buff) != 1)
        return false;

    return true;
}

void solve() {
    s = buff;
    n = sz(s);

    for (int i = 0; i < n - 1; ++i)
        if (s.substr(i, 2) == "AC") {
            printf("Yes\n");
            return ;
        }

    printf("No\n");
}

int main() {
#if SEREZHKA
    freopen("file.in", "r", stdin);
#endif

    while (read())
        solve();

    return 0;
}
