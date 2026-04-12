///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline ll ad(ll x,ll y){ll ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll sub(ll x,ll y){ll ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll gun(ll x,ll y){ll ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
const int N = 2e6 + 100;
namespace Combi {
    int fact[N], inv[N];

    int bm(int b, int p, int m) {
        if(p == 0) return 1%m;
        int t = bm(b,p/2,m);
        t = (1ll*t*t)%m;
        if(p&1) return 1ll*t*b%m;
        return t;
    }

    int C(int n, int r) {
        if(n < 0 or r < 0 or r > n) return 0;
        int ret = 1ll*fact[n]*inv[r]%mod;
        ret = 1ll*ret*inv[n-r]%mod;
        return ret;
    }
    // X1 + X2 + ... + Xvar = Sum
    int no_of_eqns(int sum, int var) {
        return C(sum+var-1,var-1); // Xi >= 0
        // return C(sum-1,var-1); // Xi > 0
    }
    void init() {
        fact[0] = 1;
        for(int i = 1; i < N; i++) {
            fact[i] = 1ll*fact[i-1]*i%mod;
        }
        inv[N-1] = bm(fact[N-1], mod-2, mod);
        for(int i = N-2; i >= 0; i--) {
            inv[i] = 1ll*inv[i+1]*(i+1)%mod;
        }
    }
}

const int M=200005;
int p[M];
int pre[M];
int qry(int l,int r)
{
    if(l>r)return 0;
    if(l==0)return pre[r];
    int ret=sub(pre[r],pre[l-1]);
    return ret;
}
 main()

{
    fast
    Combi::init();
    int n,m,k;
    cin>>n>>m>>k;
    f(i,1,M-1)
    {
        p[i]=ad(p[i-1],i);
    }
    f(i,1,M-1)
    {
        pre[i]=ad(pre[i-1],p[i]);
    }
    int ses=0;
    f(i,1,n)
    {
        f(j,1,m)
        {
            int ans=0;
            int dan=m-j;
            int koyta=n-i;
            int ad_sum=qry(dan,dan+koyta);
            int sub_sum=qry(0,koyta);
            int sum=sub(ad_sum,sub_sum);
            ans=ad(ans,sum);

            koyta=i-1;
            ad_sum=qry(dan+1,dan+koyta);
            sub_sum=qry(1,koyta);
            sum=sub(ad_sum,sub_sum);
            ans=ad(ans,sum);


            dan=j-1;
            koyta=i-1;
            ad_sum=qry(dan+1,dan+koyta);
            sub_sum=qry(1,koyta);
            sum=sub(ad_sum,sub_sum);
            ans=ad(ans,sum);



            koyta=n-i;
            ad_sum=qry(dan,dan+koyta);
            sub_sum=qry(0,koyta);
            sum=sub(ad_sum,sub_sum);
            ans=ad(ans,sum);



            int niche=n-i;
            ans=ad(ans,p[niche]);

            int upor=i-1;
            ans=ad(ans,p[upor]);

            ses=ad(ses,ans);

        }
    }
    int x=Combi::C(n*m-2,k-2);
    ses=gun(ses,x);
    ses=gun(ses,bigmod(2LL,mod-2));
    cout<<ses<<endl;
    return 0;

}



































