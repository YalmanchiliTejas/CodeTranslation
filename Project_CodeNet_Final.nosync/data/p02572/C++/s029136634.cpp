#include<bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
typedef long long int ll;
typedef string S;
#define M 1e18
#define AS 250005
#define in(x)  cin>>x
#define in4(w,x,y,z) cin>>w>>x>>y>>z
#define in3(x,y,z) cin>>x>>y>>z
#define o(x)  cout<<x
#define o2(x,y) cout<<x<<' '<<y;
#define o3(x,y,z) cout<<x<<' '<<y<<' '<<z
#define o4(w,x,y,z)cout<<w<<' '<<x<<' '<<y<<' '<<z
#define sp cout<<' '
#define nw cout<<endl
#define rt return
#define fr(i,a,n) for(ll i=a;i<=n;i++)
#define frm(i,a,n) for(ll i=n;i>=a;i--)
#define P pair<ll,ll>
#define vc vector<ll>
#define pb push_back
#define MP map<ll,ll>
bool sortin(const pair<ll,ll> &e,const pair<ll,ll> &f){return (e.first<f.first);}
bool POT(ll x){return x && (!(x&(x-1)));}
ll i,j,k,l,m,n,p,q,r,a,b,c,x,y,z,ts,mn=1e18,mod=1e9+7;
ll ar[AS],br[AS],xr[AS],tem[AS];
int main()
{
    fast;
    in(n);
    fr(i,1,n)in(ar[i]),br[i]=(br[i-1]+ar[i])%mod;

    fr(i,1,n-1)
    {
        c=(c+(ar[i]*(br[n]-br[i]+mod)%mod)%mod)%mod;

    }
    o(c);
}

