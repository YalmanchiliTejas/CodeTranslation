#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define maxe(a,b,c) max(a,max(b,c))
#define eb emplace_back
#define em emplace
#define print(x) cout<<x<<endl;
#define fill(a,val) memset(a,val,sizeof(a))
#define in(k) int k;cin>>k
#define edl cout<<"\n"
#define ll  long long
#define ld  long double
#define mp  make_pair
#define ff  first
#define ss  second
#define pii pair<ll,ll>
#define sq(x) ((x)*(x))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
const ll mod=1e9+7;
signed main()
{
    //cout<<fixed<<setprecision(20);
    fastio;
    in(n);
    ll a[n];
    fr(i,0,n-1)
    cin>>a[i];
    ll d1[n][n];
    ll d2[n][n];
    fr(i,0,n-1)
    {
        d2[i][i]=0;
        d1[i][i]=a[i];
    }
    fr(i,0,n-2)
    {
        int x=0,y=i+1;
        for(int j=n-2;j>=i;j--)
        {
            d1[x][y]=max(a[y]+d2[x][y-1],a[x]+d2[x+1][y]);
            if(a[y]+d2[x][y-1]>a[x]+d2[x+1][y])
            d2[x][y]=d1[x][y-1];
            else
            d2[x][y]=d1[x+1][y];
            x++;y++;
        }
    }
    print(d1[0][n-1]-d2[0][n-1]);
    //printclock;
    return 0;
}