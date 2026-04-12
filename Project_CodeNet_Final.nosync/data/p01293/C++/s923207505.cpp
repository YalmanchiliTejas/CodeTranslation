#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;
const long double PI = acos((long double)(-1));

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

map<char, int> mp;
void solve() {
    char t; cin >> t; if (t == '#') exit(0);
    array<array<string, 13>, 4> vs; for (int i = 0; i < 4; i++) for (int j = 0; j < 13; j++) cin >> vs[i][j];
    int ns = 0, ew = 0;
    int idx = 0;
    for (int turn = 0; turn < 13; turn++) {
        char c = vs[idx][turn][1];
        vector<ll> s(4);
        for (int i = 0; i < 4; i++) {
            s[i] += mp[vs[i][turn][0]];
            if (vs[i][turn][1] == t) s[i] += INF;
            else if (vs[i][turn][1] == c) s[i] += inf;
        }
        idx = max_element(s.begin(), s.end()) - s.begin();
        if (idx % 2 == 0) ns++;
        else ew++;
    }
    if (ns > ew) printf("NS %d\n", ns - 6);
    else printf("EW %d\n", ew - 6);
}

int main()
{
    /*
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    */
    for (int i = 2; i < 10; i++) mp[(char)('0' + i)] = i;
    mp['T'] = 10;
    mp['J'] = 11;
    mp['Q'] = 12;
    mp['K'] = 13;
    mp['A'] = 14;

	int kkt = 89;
	while (kkt) {
		solve();
	}
    return 0;
}
