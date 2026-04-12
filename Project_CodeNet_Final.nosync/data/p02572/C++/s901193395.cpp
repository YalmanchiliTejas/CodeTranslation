
#include <bits/stdc++.h>

#define crap ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define CN cout<<"No\n"
#define CY cout<<"Yes\n"

using namespace std;
using ll = long long;
void solve()
{
    ll n; cin>>n;
    vector<ll>v(n);
    rep(i,n) cin>>v[i];
    vector<ll>c(n+1,0);
    for(int i=1;i<=n;i++)
    {
        c[i]=(c[i-1]+v[i-1])%1000000007;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+(c[i]*v[i])%1000000007)%1000000007;
    }
    cout<<ans<<"\n";
}
int main()
{
    crap;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin) ;
        freopen("output.txt","w", stdout) ;
        freopen("error.txt","w", stderr) ;
    #endif
    int t;t=1;
 //  cin>>t;
    while(t--)
        {solve();}
    return 0;
}