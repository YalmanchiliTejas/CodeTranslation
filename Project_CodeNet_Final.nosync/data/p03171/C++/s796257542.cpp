#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=b-1;i>=a;i--)
const ll maxn=3e3+5;
ll n,a[maxn],dp[maxn][maxn];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(r,0,n) {
        dp[r][r]=a[r];
        per(l,0,r)
           dp[l][r]=max(a[r]-dp[l][r-1], a[l]-dp[l+1][r]);
    }
    cout<<dp[0][n-1]<<"\n";
}