#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template <typename X> ostream& operator << (ostream& x,const vector<X>& v){for(ll i=0;i<v.size();++i) x<<v[i]<<" ";return x;}
template <typename X> ostream& operator << (ostream& x,const set<X>& v){for(auto it:v) x<<it<<" ";return x;}
template <typename X, typename Y> ostream& operator << (ostream& x, const pair<X,Y>& v) {x<<v.ff<<" "<<v.ss;return x;}
template <typename T, typename S> ostream& operator << (ostream& os, const map<T, S>& v) { for (auto it : v) os << it.first << "=>" << it.second << endl; return os; }
struct pair_hash {inline std::size_t operator()(const std::pair<ll, ll> & v) const {return v.first*31+v.second;}};
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define fr first
#define sc second
#define prnt(m) for(auto it = m.begin() ; it != m.end() ; ++it){cout<<*it<<endl;}
#define tra(it,m) for(auto it=m.begin();it!=m.end();++it)
#define DBG(x) cout<<"# # #     "<<x<<'\n';
#define fri(i,s,n) for(long long i=s;i<n;i++)
#define mod 1000000007LL
#define mod2 998244353
#define vct2 vector<vector<ll>>
#define vct vector<ll>
#define pll pair<ll,ll>
#define rz(n) resize(n)
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define arrin(a,n) for(ll i = 0; i < n ; i++){cin>>a[i];}
#define arrout(a,n) for(ll i = 0;i < n; i++){cout<<a[i]<<" ";}
#define ex(s) cout<<s<<endl,exit(0);
#define infy 2e18
#define five 100005;
#define six 1000005;
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
//___________________________________________________________________________________________________________________________________________________________
const int N = 3003;
ll dp[N][N][3];
// 0 dont take
// 1 take
// 2 both
int n;
ll a[N];
ll ans;
ll f(int i,int j,int k)
{
       if(j<0){
              return 0;
       }
       if(j==0){
              return n-i+1;
       }
       if(i==n){
              if(j!=0){return 0;}
       }
       if(dp[i][j][k] != -1){return dp[i][j][k];}
       if(k==1){
              dp[i][j][k] = 0;
              dp[i][j][k] += f(i+1,j-a[i],2);
       }
       else{
              dp[i][j][k] = 0;
              dp[i][j][k] += (f(i+1,j-a[i],2) + f(i+1,j,2))%mod2;

       }
       dp[i][j][k] %= mod2;
       return dp[i][j][k];
}
int main(){
       memset(dp,-1,sizeof dp);
       ll s;
       cin>>n>>s;
       arrin(a,n);
       ans = 0;
       fri(i,0,n){
              ans += f(i,s,1)*(i+1);
              ans %= mod2;
       }
       cout<<ans<<endl;
}
