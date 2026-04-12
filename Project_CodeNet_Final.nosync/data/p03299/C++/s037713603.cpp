#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

const int N = 105, mod = 1e9 + 7;
int n, h[N];

void add (int &_a, int _b) {
    assert(_b >= 0 && _b < mod);
    _a += _b;
    if (_a >= mod) _a -= mod;
}

int binPow (int _a, int _n) {
    int ret = 1;
    for (; _n; _n >>= 1, _a = 1LL * _a * _a % mod) if (_n & 1) ret = 1LL * ret * _a % mod;
    return ret;
}

pair<int, int> solve (int l, int r) {
    int minH = mod;

    bool rect = 1;
    for (int i = l; i + 1 <= r; ++i) if (h[i] != h[i + 1]) rect = 0;

    if (rect) return { ( (binPow(2, r - l + 1) + binPow(2, min(h[l] - h[l - 1], h[r] - h[r + 1]) ) ) % mod - 2 + mod) % mod,
                      binPow(2, min(h[l] - h[l - 1], h[r] - h[r + 1]) ) };

    for (int i = l; i <= r; ++i) minH = min(minH, h[i]);
    vector< pair<int, int> > dp;
    vector< pair<int, int> > range;
    for (int i = l, lst = -1; i <= r; ++i) {
        if (h[i] == minH) lst = -1;
        else {
            if (lst == -1) lst = i;
            if (i == r || h[i + 1] == minH) dp.pb( { solve(lst, i) } );
        }
    }
    for (int i = l, lst = -1; i <= r; ++i) {
        if (h[i] > minH) lst = -1;
        else {
            if (lst == -1) lst = i;
            if (i == r || h[i + 1] > minH) range.pb( { lst, i } );
        }
    }

//    cout << "l = " << l << "  r = " << r << '\n';
//    for (auto _ : dp) cout << _.fi << ' '; cout << '\n';

    pair<int, int> ret = { 0, 0 };

    int tmp = 1;
    for (auto _ : dp) tmp = 1LL * tmp * ( (_.fi + _.se) % mod) % mod;
    for (auto _ : range) tmp = 1LL * tmp * binPow(2, _.se - _.fi + 1) % mod;

//    cout << "tmp = " << tmp << '\n';

    add(ret.fi, tmp);

    tmp = 1;
    for (auto _ : dp) tmp = 1LL * tmp * _.se % mod;
    add(tmp, tmp);

//    cout << "tmp = " << tmp << '\n';

    add(ret.fi, 1LL * tmp * ( (binPow(2, minH - max(h[l - 1], h[r + 1]) - 1) - 1 + mod) % mod) % mod);

    add(ret.se, 1LL * tmp * binPow(2, minH - max(h[l - 1], h[r + 1]) - 1) % mod);

//    cout << ret.fi << "  " << ret.se << '\n';

    return ret;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];

    cout << solve(1, n).fi;

    return 0;
}
/*
3
4 2 5

320
*/
