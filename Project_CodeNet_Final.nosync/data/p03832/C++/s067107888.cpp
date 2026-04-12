#include <bits/stdc++.h>
#define MAX 10000005
#define ll long long
#define upperlimit 1000100
#define INF 1e18
#define inf 1e9
#define eps 1e-8
#define endl '\n'
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mod 1000000007
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define ios ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
ll x[100004];
long long int modpow (long long int a) {
	int res = 1;
ll j=mod-2LL;
	while (j > 0)
		if (j & 1) {
			res = (res * a) % mod;
			--j;
		}
		else {
			a = (a * a) % mod;
			j >>= 1;
		}
	return res %mod;
}
ll dp[1003][1034];
ll ff[1004];ll pinv[1003][1034];
ll powr(ll i,ll j)
{
    if(j==0)return 1;
    ll h=powr(i,j/2);
    h=h*h;
    h=h%mod;
    if(j%2==0)return h;
    h=h*i;
    h=h%mod;
    return h;
}
ll fact[1032];
int main()
{
    ios;
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    b=min(b,n/c);
    dp[a][0]=1;
    fact[0]=1;
    ff[0]=modpow(1LL);
    for(ll i=1;i<=1003;i++){fact[i]=fact[i-1]*i;fact[i]%=mod;ff[i]=modpow(fact[i]);}
    for(ll i=a;i<=b;i++)
    {
        for(ll j=c;j<=d;j++)
        {
            pinv[i][j]=modpow(powr(fact[i],j));
        }

    }
    for(ll i=c;i<=d&&i*a<=n;i++)
    {
        dp[a][i*a]=fact[i*a]*modpow(powr(fact[a],i));
        dp[a][i*a]=dp[a][i*a]%mod;
        dp[a][i*a]*=modpow(fact[i]);
        dp[a][i*a]%=mod;
    }
   // b=min(b,n/c);

    for(ll i=a+1;i<=b;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];
            for(ll k=c;k<=d&&j-i*k>=0;k++)
            {
               // cout<<i<<" "<<j<<" "<<k<<endl;
             //  if(dp[i-1][j-i*k]==0)continue;
                ll h=fact[j]*ff[k];
                h=h%mod;
                h=h*pinv[i][k];
                h=h%mod;
                h=h*ff[j-i*k];
                h=h%mod;
                h=h*dp[i-1][j-i*k];
                h=h%mod;
                dp[i][j]+=h;
                dp[i][j]%=mod;
            }

        }
        //cout<<i<<endl;
    }
    cout<<dp[b][n]<<endl;



}
