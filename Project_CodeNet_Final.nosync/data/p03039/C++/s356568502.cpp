    #include<bits/stdc++.h>
    typedef long long ll;
    using namespace std;
    const int maxn=2e5+10;
    const int mod=1e9+7;
    ll f[maxn];
    ll p[maxn];
    ll pows(ll a,ll b)
    {
         ll re=1;
         while(b)
         {
            if(b&1)
            re=re*a%mod;
                a=a*a%mod;
                b/=2;
         }
         return re%mod;
    }
    void inint()
    {
        f[0]=p[0]=1;
        for(int i=1;i<=maxn;i++)
            f[i]=f[i-1]*i%mod,p[i]=pows(f[i],mod-2)%mod;
    }
    ll C(ll n,ll m)
    {
        ll ans=(ll)f[n]*p[n-m]%mod*p[m]%mod;
     //   cout<<f[n]<<' '<<p[n-m]<<' '<<p[m]<<' '<<ans<<endl;
     //cout<<ans<<endl;
         return ans;
    }
    ll solve(ll n,ll m,ll k)
    {
           ll ans=0;
           for(int i=1;i<n  ;i++)
           {
               ans=(ans+C(n*m-2,k-2)*(n-i)%mod*m%mod*m%mod*i%mod)%mod;
              // cout<<ans<<endl;
           }

           return ans%mod;
    }
    int main()
    {
        ll n,m,k;
         cin>>n>>m>>k;
         inint();
         ll ans=(solve(n,m,k)+solve(m,n,k))%mod;
         printf("%lld\n",ans);
        return 0;
    }
