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
#define  lb(v,val)  lower_bound(ALL(v), val); 
#define  ub(v,val)  upper_bound(ALL(v), val); 
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
#define N 100002

//------------------------ Global VARIABLE ------------------------------------
 


//------------------------------------------------------------------------------

void dquit()
{  

  int n;  cin>>n; 

  vi v(n+1);  rep(i,1,n+1)    cin>>v[i];

  map<pii,int> dp;   

  dp[{0,0}]=0; dp[{1,1}]=v[1];  dp[{2,1}]=v[2];

  // dp[3][]={dp[1]+v[3],dp[1].S+1}

    dp[{3,2}]=v[1]+v[3] ;

    dp[{3,1}]=v[3];

    dp[{4,2}]=max(v[2]+v[4] , v[1]+v[4] ) ;



  rep(i,5,n+1)
  {
     int p1= (i+1)/2 , p2= i/2 , p3=(i-1)/2;

    dp[{i,p1}]=-INF;
    rep(j,2,5)
    {
      pii pr={i-j,p1-1};

      if(present(dp,pr))
        dp[{i,p1}]=max(dp[{i,p1}],dp[pr]+v[i]);
     } 

         dp[{i,p2}]=-INF;
    rep(j,2,5)
    {
      pii pr={i-j,p2-1};
      if(present(dp,pr))
        dp[{i,p2}]=max(dp[{i,p2}],dp[pr]+v[i]);
     } 

         dp[{i,p3}]=-INF;
    rep(j,2,5)
    {
      pii pr={i-j,p3-1};

      if(present(dp,pr))
        dp[{i,p3}]=max(dp[{i,p3}],dp[pr]+v[i]);
     } 

  } 

  // for(auto K: dp)
  // {
  //   cout<<K.F.F<<" "<<K.F.S<< " "<<K.S<<nl;
  // }


int ans=-INF;
rep(i,1,n+1)
{
   pii p1={i,n/2};
   if(present(dp,p1))
   {
    // cerr<<dp[p1]<<" "<<p1.F<<" ";
  ans=max(dp[p1],ans);
   }
  
}

cout<<ans;  

}

 
signed main()
{
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    freopen("error.txt","w", stderr);
   #endif
 
//////////////////////
     FAST    // MAKE IT FAST
//////////////////////
//()()()()()()()()(((()()()()(()()()()()()()()()()(((()()()()(()(()()()(((((()(()()()())()()()()()()()()()()))))))))))))       
   

 
//()()()()()()()()(((()()()()(()()()()()()()()()()(((()()()()(()(()()()(((((()(()()()())()()()()()()()()()()))))))))))))       
   
   int t; 
   t=1;    

   int co=1;

///////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|||||
               // cin>>t;        ////////>>>>>>>
//////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|||||

    while(t--)
    {
       // cout<<"Case #"<<co<<": ";

      dquit();
      cout<<nl;     
      co++;  
    }

 // #ifndef ONLINE_JUDGE
 //  cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
 // #endif      

   return 0;
}