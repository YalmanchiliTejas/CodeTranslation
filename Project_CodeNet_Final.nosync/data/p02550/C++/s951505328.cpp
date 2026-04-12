#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
template <class T> vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
template <typename T> struct edge {
    int to;
    T cost;
    edge(int t, T c) : to(t), cost(c) {}
};
template <typename T> using WGraph = vector<vector<edge<T>>>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    ll res = 0;
    ll sum = X;
    set<int> se;
    se.insert(X);
    ll len = 1;
    ll f = 0;
    vector<ll> hist;
    vector<ll> tim(M + 1, -1);
    tim[X] = 1;
    hist.pb(X);
    if(N <= M) {
        res = X;
        for(int i = 0; i < N - 1; i++) {
            X = (X * X) % M;
            res += X;
        }
        cout << res << endl;
        return 0;
    }

    while(1) {
        len++;
        X = (X * X) % M;
        sum += X;
        if(X == 0) {
            f = 1;
            break;
        } else if(X == 1) {
            f = 2;
            break;
        }
        if(se.count(X)) {
            sum -= X;
            len = len - tim[X];
            break;
        } else {
            se.insert(X);
            tim[X] = len;
            hist.pb(X);
        }
    }

    if(f == 1) {
        cout << sum << endl;
    } else if(f == 2) {
        cout << sum + (N - len) << endl;
    } else {
        N -= tim[X];
        ll s = 0, rest = 0;
        rep(j, tim[X] - 1) s += hist[j];
        rep(j, N % len + tim[X]) rest += hist[j];
        sum -= s;
        res = sum * (N / len) + rest;
        cout << res << endl;
    }
}