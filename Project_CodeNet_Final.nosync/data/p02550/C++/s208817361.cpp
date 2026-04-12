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
    ll sum = 0;
    vector<pll> hist(M);
    bool f = 0;
    for(ll i = 0; i < N; i++) {
        if(hist[X].first & !f) {
            ll len = i - hist[X].first, cnt = (N - i - 1) / len;
            i += len * cnt;
            sum += (sum - hist[X].second) * cnt;
            f = 1;
        } else {
            hist[X] = MP(i, sum);
        }
        sum += X;
        X = (X * X) % M;
    }
    cout << sum << endl;
}