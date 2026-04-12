#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(ll i=a;i<=(ll)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    cs
    int n;cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<vector<ll>> dp(n,vector<ll>(n));
    rep(i,n) dp[i][i]=v[i];
    repp(i,1,n-1) {
        repp(j,0,n-1-i) {
            dp[j][j+i]=max(v[j]-dp[j+1][j+i],v[j+i]-dp[j][j+i-1]);
        }
    }
    cout<<dp[0][n-1];
}