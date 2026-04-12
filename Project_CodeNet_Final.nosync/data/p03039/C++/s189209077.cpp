#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false)
#define ll  long long
ll a[300300], b[302000], fc[300000];
vector<ll>v;

ll f(ll n, ll b, ll mod)
{
    ll aa, ans=1;
    if(!b) return 1;
    if(b%2) ans=n;
    aa = f(n,b/2,mod);
    return ((aa*aa)%mod*ans)%mod;
}
int main()
{
    IO;
    ll i, j=1, k = 0, mod = 1e9+7, m, mx, n, l = 1, p, t, h, kk=0, cnt=0;
    cin>>n>>m>>k;  p = n*m; fc[0]=1;

    for(i=1; i<=p; i++) fc[i]=(fc[i-1]*i)%mod;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            l = (n-i)*((j*(j-1))/2+((m-j)*(m-j+1))/2)+m*((n-i)*(n-i+1))/2+((m-j)*(m-j+1))/2;
            cnt=(cnt+l)%mod;
        }
    }
    l = (fc[p-2]*f((fc[p-k]*fc[k-2])%mod,mod-2,mod))%mod;
    cout<<(l*cnt)%mod<<endl;
    return 0;
}
