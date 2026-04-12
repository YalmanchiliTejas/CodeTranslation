#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define INF (ll)1e18
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
#define cauto const auto&
#define println(v) cout << v << "\n";
#define debug(v) if (debug_mode) cout << v << "\n";
#define dump(x) if (debug_mode) cerr << #x << " = " << (x) << endl

bool debug_mode = true;

void show(const vector<ll>& arr, bool show_index = false, ll w = 4) {
    if (!debug_mode) return;

    ll max_value = 0;
    REP(i, SZ(arr)) {
        if (abs(INF - arr[i]) >= 1e5) max_value = max(max_value, arr[i]);
    }

    w = max(w, SZ(to_string(max_value))+1LL);

    if (show_index) {
        REP(i, arr.size()) {
            cout << right << setw(w) << i;
        }
        cout << endl;
    }

    REP(i, arr.size()){
        if (abs(INF - arr[i]) < 1e5) {
            cout << right << setw(w) << (arr[i] == INF ? "INF" : "inf");
        } else {
            cout << right << setw(w) << arr[i];
        }
    }
    cout << endl;
}

void show(const vector<vector<ll>>& arr, ll w = 4) {
    if (!debug_mode) return;

    int M = arr.size(), N = arr[0].size();
    ll max_value = 0;
    REP(i, M) REP(j, N) {
            if (abs(INF - arr[i][j]) >= 1e5) max_value = max(max_value, arr[i][j]);
        }

    w = max(w, SZ(to_string(max_value))+1LL);

    cout << right << setw(w) << "#";
    REP(i, SZ(arr[0]))  {
        cout << right << setw(w) << i;
    }
    cout << endl;
    REP(i, SZ(arr)) {
        cout << right << setw(w) << i;
        REP(j, SZ(arr[0])) {
            if (abs(INF - arr[i][j]) < 1e5) {
                cout << right << setw(w) << (arr[i][j] == INF ? "INF" : "inf");
            } else {
                cout << right << setw(w) << arr[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

void show(const vector<vector<vector<ll>>>& arr, ll w = 4) {
    if (!debug_mode) return;

    REP(i, arr.size()) {
        println("i: " + to_string(i));
        show(arr[i], w);
    }
    cout << endl;
}

inline vector<vector<vector<ll>>> make_vector(ll i, ll j, ll k) {
    vector<vector<vector<ll>>> v(i, vector<vector<ll>>(j, vector<ll>(k, 0)));
    return v;
}
inline vector<vector<ll>> make_vector(ll i, ll j) {
    vector<vector<ll>> v(i, vector<ll>(j, 0));
    return v;
}

template <class InputIterator>
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
        for (ll i : std::initializer_list<ll>{args...}) {
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

    static void calc_factorial(int n) {
        fact[0] = 1;
        FOR(i, 1, n+1) {
            fact[i] = mul(fact[i-1], i);
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
        for (ll i : std::initializer_list<ll>{args...}) {
            res = mul(res, inverse(i));
        }
        return res;
    }

    template<class... A>
    static ll add(A... args) {
        ll res = 0;
        for (ll i : std::initializer_list<ll>{args...}) {
            res = (res + i) % MOD;
        }
        return res;
    }

    template<class... A>
    static ll sub(ll l, A... args) {
        ll res = l;
        for (ll i : std::initializer_list<ll>{args...}) {
            res = (res - i + MOD) % MOD;
        }
        return res;
    }
};
ll mod::fact[(int) 2e6 + 1];

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

class math {
public:

    /*
    * n <= a/b なる最大の整数nを返す
    */
    static ll floor(ll a, ll b) {
        if (b < 0) {
            a *= -1;
            b *= -1;
        }

        if (a > 0) {
            //絶対値の小さい方に丸められる(正なら負の方向)
            return a/b;
        } else {
            //よくある切り上げのテクニックの切り捨て版
            return (a-b+1)/b;
        }
    }

    /*
     * n >= a/b なる最小の整数nを返す
     */
    static ll ceil(ll a, ll b) {
        if (b < 0) {
            a *= -1;
            b *= -1;
        }

        if (a > 0) {
            //よくある切り上げのテクニック
            return (a+b-1)/b;
        } else {
            //絶対値の小さい方に丸められる(負なら正の方向)
            return a/b;
        }
    }

    /*
     * aとbの最大公約数を求める
     */
    static ll gcd(ll a, ll b) {
        long M = max(a, b);
        long m = min(a, b);

        if (m == 0) {
            return M;
        }

        return gcd(m, M%m);
    }

    /*
     * aとbの最小公倍数を求める
     */
    static ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }

    /*
     * n(2^62以下)の平方根の整数部分を返す
     * doubleの精度には限界があるので整数の二分探索で求める
     */
    static ll sqrt(ll n) {
        ll high = bit(31)+1;
        ll low = 0;

        ll mid;
        while(high - low > 1) {

            mid = (high + low) / 2;

            if (mid * mid <= n) {
                low = mid;
            } else {
                high = mid;
            }

        }

        return low;
    }

};

template <class T, class F>
ll binary_count(const vector<T>& A, const F& f) {

    int N = SZ(A);

    bool first = f(A[0]);
    bool last = f(A[N-1]);

    if (first && last) return N;
    if (!first && !last) return 0;

    int ok, ng, mid;
    if (last) {
        ok = N-1;
        ng = 0;
    } else {
        ok = 0;
        ng = N-1;
    }

    while (abs(ok - ng) > 1) {

        mid = (ok + ng) / 2;

        if (f(A[mid])) {
            ok = mid;
        } else {
            ng = mid;
        }

    }

    return (first ? ok+1 : N-ok);
}


int main()
{

    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        println("No");
    } else {
        println("Yes");
    }

    return 0;
}