#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9+1;
int dp[100005];
int n;
vector<int> a;
void solve(){
    fill(dp, dp+n, INF);
    dp[0] = a[0];
    FOR(i,1,n){
        int b = upper_bound(dp, dp+n, a[i]) - dp - 1;
        if (dp[b] <= a[i]) dp[b+1] = a[i];
        else dp[b] = a[i];
    }
    cout << lower_bound(dp, dp+n, INF) - dp << endl;
}
int main(){
    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a[n-i-1];
    solve();
}
