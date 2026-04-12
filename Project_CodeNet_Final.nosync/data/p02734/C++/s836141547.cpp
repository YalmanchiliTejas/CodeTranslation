#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=998244353;
const double pi=3.1415926535897932,eps=1e-6;
void chmax(int &x,int y){if(x < y) x = y;}
void chmin(int &x,int y){if(x > y) x = y;}
int f[3005][3005],n,a[3005],s,ans;
int main()
{
    scanf("%d%d",&n,&s);
    rep(i,1,n) scanf("%d",a+i);
    rap(i,0,n) f[i][0] = i + 1;
    rep(i,1,n) rep(j,1,s)
    {
        f[i][j] = f[i-1][j];
        if(j >= a[i]) f[i][j] += f[i-1][j-a[i]];
        f[i][j] %= mod;
    }
    rep(i,1,n) {
        ans += (ll)(f[i][s] - f[i - 1][s] + mod) * (n - i + 1) % mod;
        if(ans >= mod) ans -= mod;
    }
    printf("%d\n",ans);
    return 0;
}