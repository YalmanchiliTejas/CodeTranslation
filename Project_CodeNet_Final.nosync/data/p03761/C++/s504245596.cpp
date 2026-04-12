#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define INF (ll)2e9
#define MOD ((ll)1e9+7)
#define ALL(v) v.begin(), v.end()
#define SZ(x) ((int)(x).size())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define bit(n) (1LL<<(n))

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template<class InputIterator>
InputIterator adv(InputIterator x, typename std::iterator_traits<InputIterator>::difference_type n) {
    advance(x, n);
    return x;
}

class mod {
    static ll fact[];
public:

    template<class... A>
    static ll mul(A... args) {
        ll res = 1;
        for (ll i : std::initializer_list < ll > {args...}) {
            res = (res * i) % MOD;
        }
        return res;
    }

    static ll power(ll base, ll exp) {
        if (exp == 0) return 1;
        if (exp & 1) {
            return mul(base, power(base, exp - 1));
        } else {
            ll p = power(base, exp / 2);
            return mul(p, p);
        }
    }

    static ll factorial(int n) {
        if (fact[n] != 0) return fact[n];
        if (n == 0) return 1;
        return fact[n] = mul(n, factorial(n - 1));
    }

    static ll inverse(int n) {
        return power(n, MOD - 2);
    }

    static ll comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return mul(factorial(n), inverse(factorial(n - r)), inverse(factorial(r)));
    }

    template<class... A>
    static ll div(ll dividend, A... args) {
        ll res = dividend;
        for (ll i : std::initializer_list < ll > {args...}) {
            res = mul(res, inverse(i));
        }
        return res;
    }

    template<class... A>
    static ll add(A... args) {
        ll res = 0;
        for (ll i : std::initializer_list < ll > {args...}) {
            res = (res * i) % MOD;
        }
        return res;
    }

    template<class... A>
    static ll sub(ll l, A... args) {
        ll res = l;
        for (ll i : std::initializer_list < ll > {args...}) {
            res = (res - i + MOD) % MOD;
        }
        return res;
    }
};

ll mod::fact[(int) 1e6 + 1];

int ni() {
    int i;
    cin >> i;
    return i;
}

ll nll() {
    ll l;
    cin >> l;
    return l;
}

int main() {
    int N = ni();
    ll count[50][26] = {};
    REP(i, N) {
        string s;
        cin >> s;
        REP(j, s.length()) {
            count[i][s[j]-'a']++;
        }
    }

    string ans = "";
    REP(i, 26) {
        ll m = INF;
        REP(j, N) {
            m = min(m, count[j][i]);
        }
        REP(j, m) ans.push_back('a' + i);
    }

    cout << ans << endl;
    return 0;
}