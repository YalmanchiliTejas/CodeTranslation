/*
 *  Author  : StelaYuri
 * Language : GNU G++ 14
 */

//#pragma comment(linker,"/STACK:1024000000,1024000000")
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#include<unordered_map>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
#define closeSync ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define multiCase int T;cin>>T;for(int t=1;t<=T;t++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repp(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define perr(i,a,b) for(int i=a;i>b;i--)
#define pb push_back
#define eb emplace_back
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-12;
const double PI=acos(-1.0);
const double angcst=PI/180.0;
const ll mod=998244353;
ll max_3(ll a,ll b,ll c){if(a>b&&a>c)return a;if(b>c)return b;return c;}
ll min_3(ll a,ll b,ll c){if(a<b&&a<c)return a;if(b<c)return b;return c;}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll qmul(ll a,ll b){ll r=0;while(b){if(b&1)r=(r+a)%mod;b>>=1;a=(a+a)%mod;}return r;}
ll qpow(ll a,ll n){ll r=1;while(n){if(n&1)r=(r*a)%mod;n>>=1;a=(a*a)%mod;}return r;}
ll qpow(ll a,ll n,ll p){ll r=1;while(n){if(n&1)r=(r*a)%p;n>>=1;a=(a*a)%p;}return r;}



void solve()
{
    int n;
    cin>>n;
    cout<<(n>=30?"Yes\n":"No\n");
}
int main()
{
    closeSync;
    //multiCase
    {
        solve();
    }
    return 0;
}
