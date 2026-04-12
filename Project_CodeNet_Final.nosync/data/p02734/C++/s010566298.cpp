#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi       acos(-1)
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
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

#define int long long ////////////
#define MOD 1000000007    ////////
#define POD 998244353 ////////
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
#define  lb(v,val)  lower_bound(ALL(v), val)
#define  ub(v,val)  upper_bound(ALL(v), val)
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define maxc(v) *max_element(ALL(v))
#define minc(v) *min_element(ALL(v))
 /*
#define dbg1(a) cout<<" *"<<a<<" ";
#define dbg2(a,b) cout<<" *"<<a<<" **"<<b<<" "     /////
#define dbg cout<<"move"
*/

#define vin(v,n);   vi v(n); rep(i,0,n)  cin>>v[i];
#define dbg cerr <<"At line "<<__LINE__<<" move "<<nl
#define dbg1(x) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<nl
#define dbg2(x,y) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<nl
#define dbg3(x,y,z) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<nl
#define prv(v);     rep(i,0,sz(v))  cerr<<v[i]<<" ";
#define nl "\n"
#define sz(s)         (int)((s).size())
#define coutsp(k)   cout<<setprecision(k)  //set precision (total length k icluding decimal and non decimal)
#define coutfsp(k)   cout<<fixed<<setprecision(k)  //fixed set precision(after decimal fixing)

#define isvowel(a) (a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
#define  INF   (int)2e18 


//------------------------ Global VARIABLE ------------------------------------

const int N=3004;

int n,S;  

vi a;

int dp[N][N][2];

//------------------------ Global VARIABLE ------------------------------------

int recurso(int n1, int sum  , int t )
{

  if(sum==0) return n1+1;


  if(n1<=0||sum<0)  return 0;

  if(dp[n1][sum][t]!=-1)
    return dp[n1][sum][t];


   int ans=0;

   // dbg2(n1,r);
   
   if(t==0)
   ans+=(n-n1+1)*recurso(n1-1,sum-a[n1],1)+recurso(n1-1,sum,0);
   else if(t==1)
   ans+=recurso(n1-1,sum-a[n1],1)+recurso(n1-1,sum,1);

   return dp[n1][sum][t] = ans%POD;

}
//-------------------------------------------------------------------------------

void dquit()
{  
  cin>>n>>S;

    memset(dp,-1,sizeof(dp));
    
    a.resize(n+1);

    rep(i,1,n+1)  cin>>a[i];

    cout<<recurso(n,S,0);



}
//-------------------------------------------------------------------------------

 
signed main()
{


//--------------------------------
     FAST    // MAKE IT FAST   ---
//--------------------------------

/////////////////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////////////////// 
   
   int t;  t=1;    
   int co=1;
///////---------------------------------|||||
               // cin>>t;        ////////>>>>>>>
//////----------------------------------|||||

    while(t--)
    {
       // cout<<"Case #"<<co<<": ";

      dquit();
      cout<<nl;   //  IMPORTANT FOR NEXT LINE     
      co++;  
    }


 // #ifndef ONLINE_JUDGE
 //  cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
 // #endif      

   return 0;
}