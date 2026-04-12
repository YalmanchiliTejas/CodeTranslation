#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);
ll f(ll x, ll m) {
    return (x*x) % m;
}

int main() {

    ll N, X, M;
    cin >> N >> X >> M;

    set<ll> s, c;
    s.insert(X);
    ll t = X;
    vector<ll> v, w;
    v.push_back(X);

    for(int i = 0; i < N; i++) {
        t = f(t, M);

        if (s.count(t) == 1) {
            if (c.count(t) == 1) break;
            w.push_back(t);
            c.insert(t);
        }
        if (c.size() == 0) {
            s.insert(t);
            v.push_back(t);
        }
    }

    ll ans = 0;
    if (v.size() >= N) {
        for(int i = 0; i < N; i++) {
            ans += v[i];
        }
        cout << ans << endl;
        return 0;
    }

    for(ll i : v) {
        ans += i;
    }
    ll sum = 0;
    for (ll i : w) {
        sum += i;
    }

    N -= v.size();
    ll m = N / c.size();
    ans += sum * m;
    ll k = N - m*c.size();

    for(int i = 0; i < k; i++) {
        ans += w[i];
    }

    cout << ans << endl;

    return 0;
}