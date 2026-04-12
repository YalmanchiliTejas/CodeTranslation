#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{ for (auto v : vec) os << v << ' '; os << '\n'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{ os << '(' << pa.first << ',' << pa.second << ')'; return os; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{ cerr << " " << H; debug_out(T...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    int ans = 0;
    rep(i, n) {
        cin >> A[i];
    }
    vector<int> B = A;
    sort(all(B));
    int now = B[0], cnt = 0;
    for (int i = 0; i < n;) {
        while(now == B[i]) {
            cnt++, i++;
            if (i >= n) break;
        }
        chmax(ans, cnt);
        if (i >= n) break;
        now = B[i];
        cnt = 0;
    }
    vector<pii> X;
    rep(i, (int)A.size()) {
        X.push_back({A[i], i});
    }
    auto compare = [](pii a, pii b) {
        if (a.fi > b.fi) return true;
        else if (a.fi == b.fi) return a.se < b.se;
        else return false;
    };
    sort(all(X), compare);
    vector<int> dp(n + 1, INF);
    rep(i, (int)X.size()) {
        int idx = X[i].se;
        *lower_bound(all(dp), idx) = idx;
    }
    chmax(ans, (int)(lower_bound(all(dp), INF) - dp.begin()));
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
