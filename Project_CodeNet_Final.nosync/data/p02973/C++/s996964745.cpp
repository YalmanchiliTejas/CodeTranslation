#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define INF  (1<<30)
#define INFL (1LL<<60)
#define MOD 998244353LL
#define EPS ((ld)(1e-9))
 
#define sz(x) ((int)(x).size())
#define setz(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define rep(i, e) for (int i = 0, _##i = (e); i < _##i; i++)
#define repp(i, s, e) for (int i = (s), _##i = (e); i < _##i; i++)
#define repr(i, s, e) for (int i = (s)-1, _##i = (e); i >= _##i; i--)
#define repi(i, x) for (auto &i : (x))
 
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) { 
    return os << '(' << pai.first << ' ' << pai.second << ')';
}
 
template<typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    cout << '[';
    for (auto p : v) cout << p << ",";
    cout << "]";
    return os;
}
 
template<typename T>
ostream &operator<<(ostream &os, const set<T> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
#ifndef __SOULTCH
#define debug(...) 0
#define endl '\n'
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cout << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cout << *sdbg++;
    cout << '=' << (h) << ','; 
    _dbg(sdbg+1, a...);
}
#endif
 
template<typename T> void get_max(T &a, T b) {a = max(a, b);}
template<typename T> void get_min(T &a, T b) {a = min(a, b);}

int N, d;
int A[200000];
int dp[200001];
int main(void) {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> N;
    rep(i, N) cin >> A[i];
    reverse(A, A+N);

    int cm = 0;
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        int t = A[i];
        
        int lo = 0, hi = d;
        while(lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (dp[mid] <= t) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        d = max(d, lo + 1);
        dp[lo + 1] = t;
    }

    cout << d << endl;
}