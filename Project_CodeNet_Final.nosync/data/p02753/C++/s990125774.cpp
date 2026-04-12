#include <bits/stdc++.h>
using namespace std;
  
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi       acos(-1)
#define mp make_pair
#define pb push_back
// #define int long long ////////////
#define MOD 1000000007    ////////
#define POD 998244353 ////////
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define maxc(v) max_element(all(v))
#define minc(v) min_element(all(v))
#define F first
#define S second
#define ppb pop_back
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) (m*n)/GCD(m,n)
#define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
#define initarr(a,n,x) for (int i=0;i<n;++i) a[i]=x
#define rep(i,a,n)  for(int i=a ; i<n ; i++)
#define repe(i,a,n) for(int i=a;i<=n;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
//define ll long long
#define ld long double 
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pii > vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
typedef map<char,int> mci;
 
#define itv for(auto it= v.begin(); it != v.end(); ++it )
 
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(ALL(container),element) != container.end())
//#define invect(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.pb(tmp);commands}
//#define inset(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.insert(tmp);commands}
//#define trav(a, x) for(auto& a : x)
//#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
 
 
#define bs binary_search
#define  lb(v,val)  lower_bound(ALL(v), val); 
#define  ub(v,val)  upper_bound(ALL(v), val); 
 /*
#define dbg1(a) cout<<" *"<<a<<" ";
#define dbg2(a,b) cout<<" *"<<a<<" **"<<b<<" "     /////
#define dbg cout<<"move"
*/
#define dbg cerr <<"At line "<<__LINE__<<" move "<<nl
#define dbg1(x) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<nl
#define dbg2(x,y) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<nl
#define dbg3(x,y,z) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<nl
 
#define nl "\n"
#define sz(s)         (int)((s).size())
#define coutsp(k)   cout<<setprecision(k)  //set precision (total length k icluding decimal and non decimal)
#define coutfsp(k)   cout<<fixed<<setprecision(k)  //fixed set precision(after decimal fixing)
#define  INF   (int)1e18 
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define vin(v,n);   vi v(n); rep(i,0,n)  cin>>v[i];
#define prv(v);     rep(i,0,sz(v))  cerr<<v[i]<<" ";

#define isvowel(a) (a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
//#define siz  (int)1e8
#define N 20000

void solve()
{ 

string s;   cin>>s;

if(s=="BBB" || s=="AAA")
cout<<"No";
else
cout<<"Yes";
 
}
 
signed main()
{
 
 
 
   FAST

   
   int t; 
      t=1;              
   // cin>>t;
    while(t--)
    {
    
      solve();
      cout<<nl;
          
}
 
 
 
 
 
 
   return 0;
}