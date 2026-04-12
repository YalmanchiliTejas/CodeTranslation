#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn=3001;
typedef long long ll;
const ll mod=998244353;
int a[maxn];
int n,s;
void enter()
{
    cin>>n>>s;
    _for(i,1,n+1) cin>>a[i];
}
ll f[maxn][maxn];
void qhd()
{
    ll ans=0;
    _for(i,1,n+1)
    {
        _for(j,0,s+1)
        {
            if (j==a[i])
                f[i][j]+=ll(i);
            else if (j>a[i])
                f[i][j]+=f[i-1][j-a[i]];
            f[i][j]=f[i][j]%mod;
            f[i][j]+=f[i-1][j];
            f[i][j]=f[i][j]%mod;
        }
        ans+=f[i][s];
        ans=ans%mod;
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    enter();
    qhd();
}
