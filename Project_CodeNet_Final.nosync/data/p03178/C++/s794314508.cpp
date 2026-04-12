

/*

“Death created time to grow the things that it would kill.”

*/

#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
//#define int long long
#define mod 1000000007
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define cout1(a) cout<<a<<endl
#define cout2(a,b) cout<<a<<" "<<b<<endl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<endl
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define ms(v,n) memset((v),n,sizeof(v));
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define vpll vector<pll>
#define maxi(a,b,c) max(a,max(b,c))
#define maxii(a,b,c,d) max(max(a,b),max(c,d))
#define mini(a,b,c) min(a,min(b,c))
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
#define ad(a,b)  (a%mod+b%mod+mod)%mod
#define nl endl
#define inf 1e18
#define cases ll t;cin>>t;while(t--)
#define BLOCK 500
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;

string k;
ll d,len;
char cad[100];

ll dp[10005][2][101];
bool vis[10005][2][101];


ll go(ll pos,ll flag,ll sum)
{
    if(pos==len)
    {
        return (sum%d==0);
    }

    ll &ret=dp[pos][flag][sum];
    bool &v=vis[pos][flag][sum];

    if(v)
    return ret;

    v=true;

    ll ko=flag? k[pos]-'0':9;

    ll ans=0;


    for(ll i=0;i<=ko;i++)
    {
        ans=ad(ans,go(pos+1,flag && i==ko,(sum+i)%d));

    }

    return ret=ans;

}

ll solve(string x)
{
    // sprintf(cad,"%s",x);
    len=x.size();
   // ms(vis,false);
    return go(0,1,0);

}

int main()
{
    
    // fast
    cin>>k>>d;
    
    ll ans=solve(k)-1;
    if(ans==-1)
    ans=mod-1;

    cout<<ans;
       
    return 0;
    
}

