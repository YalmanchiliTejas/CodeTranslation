#include <bits/stdc++.h>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }
 
template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}
 
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}
 
const int MN = 3030;
int n;
V<ll> a;
ll dp[MN][MN];
bool vis[MN][MN];
ll solve(int l, int r) {
    if (r + 1 == l) return 0;
    if (vis[l][r]) return dp[l][r];
    vis[l][r] = true;
    ll ans = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
    return dp[l][r] = ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    a = V<ll>(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0, n-1) << endl;
    return 0;
}