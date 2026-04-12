/**
stirling number
*/

#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define sd second
#define ll long long
 
using namespace std;
 
const int maxn = 3010;
const ll oo = 1e18;
 
int n,base;
ll p1[maxn*maxn],p2[maxn],C[maxn][maxn],f[maxn][maxn],pp[maxn];
 
ll sum(ll a, ll b) {
    return (a+b)%base;
}
 
ll sub(ll a, ll b) {
    return (a-b+base)%base;
}
 
ll mul(ll a, ll b) {
    return (a*b)%base;
}
 
ll pw(ll a, ll b) {
    if (b == 0) return 1ll;
    if (b == 1) return a;
    ll tg = pw(a,b/2);
    tg = mul(tg,tg);
    if (b%2) return mul(tg,a);
    else return tg;
 
}
 
void init() {
    for (int i=0;i<maxn;i++) {
        C[0][i]=1;
        for (int k=1;k<=i;k++) C[k][i] = sum(C[k-1][i-1],C[k][i-1]);
    }
    p2[0]=1; p1[0] = 1;
    for (int i=1;i<maxn;i++) p2[i] = (p2[i-1] * 2) % (base-1);
    for (int i=0;i<=n;i++) pp[i] = pw(2ll,p2[n-i]);
    for (int i=1;i<maxn*maxn;i++) p1[i] = (p1[i-1] * 2) % base;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
  //  freopen("in.txt","r",stdin);
    cin>>n>>base;
    init();
    f[0][0] = 1;
    for (int i=0;i<=n;i++) {
        for (int j=1;j<=i;j++) f[i][j] = sum(f[i-1][j-1], mul(f[i-1][j],1ll*j));
    }
    ll ans = 0;
    for (int i=0;i<=n;i++) {
       // cout<<dp[i]<<" "<<C[i][n]<<endl;
        ll dp =0;
        for (int j=0;j<=i;j++) {
            dp = sum(dp, mul(f[i][j], mul(p1[(n-i)*j] , pp[i])));
            if (j) dp = sum(dp,mul(mul(f[i][j],j), mul(p1[(n-i)*(j-1)] , pp[i])));
        }
        if (i%2==0) ans = sum(ans,mul(dp,C[i][n]));
        else ans = sub(ans,mul(dp,C[i][n]));
    }
    cout<<ans;
}