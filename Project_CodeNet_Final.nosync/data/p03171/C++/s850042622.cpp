#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
vector <vector<int>> dp(3010,vector <int>(3010));
vector <int> a(3010);
int solve(int l, int r, bool p){
    if(l == r){
        if(p == 1) return - (dp[l][l] = a[l]);
        else return dp[l][l] = a[l];
    }
    if(dp[l][r]){
        return dp[l][r];
    }
    if(p == 1){
        return dp[l][r] = min( solve(l+1,r,0) - a[l], solve(l, r-1,0) - a[r]);
    }else{
        return dp[l][r] = max(solve(l+1, r, 1) + a[l], solve(l, r-1, 1) + a[r]);
    }
}
signed main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    int l = 0, r = n-1;
    rep(i,n) cin>>a[i];
    solve(l, r, 0);
    cout<<solve(l, r, 0)<<endl;
    //cout<<dp[l][r]<<endl;
}
