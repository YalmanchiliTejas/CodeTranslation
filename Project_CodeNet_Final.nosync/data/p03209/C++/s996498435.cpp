#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <set>
#include <ctime>
#include <map>
#include <cstring>
#include <iterator>
#include <queue>
#include <assert.h>
#include <bitset>
#include <complex>
#include <unordered_map>

//#pragma comment(linker, "/STACK:512000000")

using namespace std;

#define pb emplace_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int infi = 1e9 + 7;
const ll infl = (ll)1e18 + (ll)7;

ll len[60];
ll cnt_p[60];

int32_t main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("customs.in", "r", stdin); freopen("customs.out", "w", stdout);
    len[0] = cnt_p[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        len[i] = len[i - 1] * 2 + 3;
        cnt_p[i] = cnt_p[i - 1] * 2 + 1;
    }
    int n;
    ll x;
    cin >> n >> x;
    ll ans = 0;
    while (x > 0) {
        if (n == 0) {
            ans += 1;
            break;
        }
        if (x == 1)
            break;
        --x;
        if (x <= len[n - 1]) {
            --n;
            continue;
        }
        ans += cnt_p[n - 1];
        x -= len[n - 1];
        ++ans;
        --x;
        if (!x)
            break;
        if (x <= len[n - 1]) {
            --n;
            continue;
        }
        ans += cnt_p[n - 1];
        break;
    }
    cout << ans << endl;

    return 0;
}