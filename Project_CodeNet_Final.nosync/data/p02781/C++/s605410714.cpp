#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
#define REP(i, n) for (int64_t i = 0; i < (int64_t)n; i++)
#define REP_FOR(i, a, b) for (int64_t i = (int64_t)a; i < (int64_t)b; i++)
#define REP_REV(i, a, b) for (int64_t i = (int64_t)a; i > (int64_t)b; i--)
#define FORALL(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int64_t, int64_t> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int64_t> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int64_t infi = 1147483600;
const ll infl = 4e18 + 5;
const char EOL = '\n';
//cout << fixed << setprecision(17) << res << endl;
const ll MOD = 1000000007;

#define M 1000000007

ll comb(ll a, ll b) {
    ll res = 1;
    for (ll i = 0; i < b; ++i) {
        res *= (a-i);
    }
    for (ll i = 0; i < b; ++i) {
        res /= (b-i);
    }
    return res;
}

ll pow(ll a, ll b) {
    if (b == 1) return a;
    if (b <= 0) return 1;
    ll res = pow(a, b/2);
    res = res * res;
    if (b%2 == 1) res *= a;
    return res;
}

int main() {
    string s;
    ll n, k;
    cin >> s >> k;
    n = s.length();
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        if (k == 0) break;
        int c = (int)(s[i]-'0');
        if (c > 0) {
            res += (c-1) * comb((n-i-1), k-1) * pow(9, k-1);
            //cerr << i << ": +" << (c-1) * comb((n-i-1), k-1) * pow(9, k-1) << endl;
            res += comb((n-i-1), k) * pow(9, k);
            //cerr << i << ": +" << comb((n-i-1), k) * pow(9, k) << endl;
            --k;
        }
    }
    if (k == 0) {
        ++res;
    }
    cout << res << endl;
}
