#include"bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define double long double
#define int long long
#define pb push_back 
#define Z(c) (int)(c).size()
#define L(c) c[Z(c)-1]
#define F first
#define S second
#define nl "\n"
#define mii map<int,int> 
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define rep(i,iv,n) for(int (i)=(iv);(i)<(n);++(i))
#define FO fflush(stdout) 
#define D1(x) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<nl
#define D2(x,y) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<nl
#define D3(x,y,z) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<nl
#define tr(it,ct) for(auto &(it) : (ct))
#define pi acos(-1)
#define prt(ct) for(auto &(it) : (ct)) cerr<<it<<" "; cerr<<nl
#define prtp(ct) for(auto &(it) : (ct)) cerr<<it.F<<" "<<it.S<<nl; cerr<<nl

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > pii;
typedef vector< pii > vp;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> baap;

void swap(char &a,char &b)
{ auto tm=a; a=b; b=tm; }
                                   
 
  const int mod=1000000007;
  const int mod2=998244353;
  const int INF=1e16+18;
  const int N=2e5+35;
  const int M=2e4;
  
  int dp[3003][3003];
 int ct[3003];
 void fft()           
 {
   int n,s; cin>>n>>s; vi v(n+1); rep(i,1,n+1) cin>>v[i];
   
   dp[1][v[1]]=1; ct[v[1]]+=1;
   
   for(int i=2;i<=n;++i){
        dp[i][v[i]]=i;
     for(int j=v[i]+1;j<=s;++j){
         dp[i][j]=ct[j-v[i]];

     }
     
      for(int j=v[i];j<=s;++j) (ct[j]+=dp[i][j])%=mod2;    
   }
   
  
   int ans=0;
   for(int i=1;i<=n;++i) (ans+=(n-i+1)*dp[i][s])%=mod2;
   
   cout<<ans;
   
 }

signed main()
{ 
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   
   int t=1;                         
 //  cin>>t;

  rep(i,1,t+1)
  { // cout<<"Case #"<<i<<": ";
   fft();
   if(i<t)
   cout<<nl;
  }
  
 
 return 0; 
}