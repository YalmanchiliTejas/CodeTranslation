#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef vector<int>vi;
typedef pair<int,int>pi;
typedef vector<pi>vpi;
typedef vector<vi>vvi;
#define double long double
#define pow powl
#define sqrt sqrtl
#define cbrt cbrtl
#define floor floorl
#define ceil ceill
#define pb push_back
#define ep emplace_back
#define PB pop_back
#define pf push_front
#define ef emplace_front
#define PF pop_front
#define mp make_pair
#define ub(a,b) upper_bound(all(a),b)-a.begin()
#define lb(a,b) lower_bound(all(a),b)-a.begin()
#define bs(a,b) binary_search(all(a),b)
#define mem(a,b) memset(a,b,sizeof(a))
#define in(a,n) FOR(i,0,n-1) cin>>a[i]
#define in1(a,n) FOR(i,1,n) cin>>a[i]
#define ff first
#define ss second
#define out(a,n) FOR(i,0,n-1) cout<<a[i]<<" ";cout<<endl;
#define out1(a,n) FOR(i,1,n) cout<<a[i]<<" ";cout<<endl;
#define clr(a) a.clear()
#define pow2(a) (1LL<<a)
#define all(a) a.begin(),a.end()
#define all1(a) a.begin()+1,a.end()
#define rall(a) a.rbegin(),a.rend()
#define rall1(a) a.rbegin(),a.rend()
#define sz(a) ((int)a.size())
#define FOR(i,a,b) for(auto i=a;i<=b;i++)
#define NFOR(i,a,b) for(auto i=a;i>=b;i--)
const int mod=1e9+7;

inline int add(int a,int b){return (a%mod + b%mod)%mod;}
inline int sub(int a ,int b){return (a%mod - b%mod + mod)%mod;}
inline int mul(int a,int b){a%=mod;b%=mod;return a*b%mod;}
inline int power(int a,int b,int MOD){a%=mod;int res=1;while(b){if(b&1){res*=a;res%=MOD;}a=a*a;a%=MOD;b>>=1;}return res;}

#define trace(x) cout<<#x<<" :: "<<x<<endl;
#define trace2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define trace3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define trace4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
clock_t time_p = clock();
void time()
{
  time_p = clock() - time_p;
  cerr << "Time elapsed : " << (double)(time_p)/CLOCKS_PER_SEC <<endl;
}
signed main()
{
     SPEED;
     int n;
     cin>>n;
     cout<<(n==7||n==5||n==3 ? "YES" : "NO")<<endl;
     time();
     return 0;
}

