#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001001001001ll;
ll n;
vector<ll> as;
vector<vector<ll>> dp;

ll dfs(int l, int r) {
    if (l == r) return dp[l][r] = as[l];
    if (dp[l][r] != -INF) return dp[l][r];

    chmax(dp[l][r], -dfs(l + 1, r) + as[l]);
    chmax(dp[l][r], -dfs(l, r - 1) + as[r]);
    return dp[l][r];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    as = vector<ll>(n);
    rep(i, n) cin>>as[i];

    dp = vector<vector<ll>>(n + 1, vector<ll>(n + 1, -INF));
    cout<<dfs(0, n - 1)<<endl;
}