#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
const int N = 200'000;
const ll INF = 200'000'000'000'001ll;
int n;
ll a[N + 1];
map<pair<int, int>, ll> memo;
ll opt(int i, int j) {
    if(not memo.count({i, j})) {
        ll& ans = memo[{i, j}];
        if(i == 0) {
            ans = j == 0 ? 0 : -INF;
        } else if((i - 1) / 2 <= j and j <= (i + 1) / 2) {
            ans = max({
                opt(i - 1, j),
                j > 0 ? a[i] + opt(max(i - 2, 0), j - 1) : -INF
            });
        } else {
            ans = -INF;
        }
    }
    return memo[{i, j}];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << opt(n, n / 2) << endl;
    return 0;
}
