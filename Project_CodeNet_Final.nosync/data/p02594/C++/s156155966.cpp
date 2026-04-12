/*   --------------------
    |       LOSER        |
    |     ~NOOBOSS~      |
     --------------------
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define      inl(x)              scanf("%lld",&x)
#define      in(x)               scanf("%d",&x)
#define      mxx                 10000000000000
#define      mnn                 -10000000000000
#define      Y()                 cout<< "YES" <<endl
#define      N()                 cout << "NO"<<endl
#define      endl                "\n"
#define      max_3(a,b,c)        max(a, max(b,c))
#define      max_4(a,b,c,d)      max(a,max(b,max(c,d)))
#define      min_3(a,b,c)        min(a, min(b,c))
#define      min_4(a,b,c,d)      min(a,min(b,min(c,d)))
#define      gcd(a,b)            __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      loser               return 0
#define      ll                  long long
#define      PI                  acos(-1)
#define      mem(a,v)            memset(a,v,sizeof(a))
#define      SORT(v)             sort(v.begin(),v.end())
#define      REV(v)              reverse(v.begin(),v.end())
#define      O(x)                cout<<x<<endl
#define      B                   begin()
#define      E                   end()
#define      V                   vector
#define      F                   first
#define      S                   second
#define      PSB                 push_back
#define      EMB                 emplace_back
#define      MP                  make_pair
#define      PII                 pair<int,int>
#define      MII                 map<int,int>
#define      InTheNameOfGod      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#define dbg(a) cerr << #a << ": "; _print(a); cerr << endl;
#else
#define dbg(a) // No more TLEs
#endif
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;//*(x.find_by_order(i)),x.order_of_key(k)
//const ll MOD = 998244353;
constexpr ll mod = 1e9  + 7;
//auto it=std:: unique(v.B,v.E);
//v.resize(std::distance(v.B,it));
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*-----*/
#define bug1(a)  cout<<a<<endl;
#define bug2(a,b)  cout<<a<<" "<<b<<endl;
#define bug3(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl;
/*----*/
const ll N=2e5+5;
vector<ll> adj[N];
/*----*/
ll power(ll n,ll p){if(p==0) return 1;if(p==1)return n;if(p%2)return power(n,p-1)*n;else{ll x=power(n,p/2);return x*x;}}
ll modpow(ll a,ll b,ll m){ll ans=1;while(b){if(b&1)ans=(ans*a)%m;b/=2;a=(a*a)%m;}return ans;}
ll binpow(ll a, ll b){ll res = 1;while (b > 0) {if (b & 1)res*=a;a*=a;b>>=1;}return res;}
ll fact(ll num){ll fac=1;while(num!=1){fac=fac*num;num--;}return fac;}
string to_binary(int x) {string s;while(x > 0) {s += (x % 2 ? '1' : '0');x /= 2;}reverse(s.begin(), s.end());return s;}
double quick_pow(double x, ll y){if(!y)  return 1.0;double ans = quick_pow(x,y>>1);ans *= ans;if(y&1)  ans *= x;return ans;}
ll nsum(ll num){return (num*(num+1))/2;}
void edge (ll u,ll v) {adj[u].PSB(v) ;adj[v].PSB(u);}
/*-----*/

/*-----*/
int main(){
   InTheNameOfGod

   ll test=1;
   //cin>>test;
   while(test--){
     ll n;
     string s;
     cin>>n;
     if(n>=30) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;

    }
  loser;
}
///////LeArN & PrAcTiCe MoRe AnD Wait FoR ThE Result///////
