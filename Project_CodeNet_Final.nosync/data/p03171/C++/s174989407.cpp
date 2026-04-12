#include<bits/stdc++.h>
#define f first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define emp emplace
#define ins insert
#define sz(s) (int)s.size()
#define rep(i,a,b) for( int i=a;i<b;i++)
#define repr(i,a,b) for( int i=a;i>=b;i--)
#define bitcount __builtin_popcount
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mem(n,m) memset(n,m,sizeof(n))
#define ii pair<int,int>
#define iii tuple<int, int, int>
#define si set<int>
#define vi vector<int>
#define vii vector<ii>
#define mi map<int,int>
#define lb lower_bound
#define ub upper_bound
#define present(s,x) (s.find(x) != s.end())
#define ford(container, it) for(auto it:container)
#define fors(container, it, a, b) for(auto it = a; it != b; it++)
#define Anurag_Gupta ios_base::sync_with_stdio(0);
#define IIIT_ALLD cin.tie(0);cout.tie(0);
#define mod 987654319
#define EPSILON 1e-9
#define PI acos(-1)
#define inf 1e17
#define int long long
#define debug(a) cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define trace(a) cerr<<#a<<": "<<a<<"\n"
#define gcd(a,b) __gcd(a,b)
using namespace std;
int add(int a, int b, int c){int res=a+b;return(res>=c?res-c:res);}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mul(int a, int b, int c){int res=(int)a*b;return(res>=c?res%c:res);}
template<typename T>T power(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T mdpower(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
/*------------------------------------------------------------------------------------------------------------------*/
const int N = 3005;
int dp[N][N][2];
int n;
int arr[N];
int solve(int i,int j,int flag)
{
    if(i<=0 or j<=0 or j<i or i>n) return 0;
    if(dp[i][j][flag]!=-1) return dp[i][j][flag];

   if(flag==0)
       return dp[i][j][flag] = max(arr[i]+solve(i+1,j,flag^1),arr[j]+solve(i,j-1,flag^1));
   else
       return dp[i][j][flag] = min(-arr[i]+solve(i+1,j,flag^1),-arr[j]+solve(i,j-1,flag^1));
        
   
}
int32_t main()
{
    Anurag_Gupta
    IIIT_ALLD
 
  
    
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
        cin>>arr[i],sum+=arr[i];
    
   
    memset(dp,-1,sizeof dp);
   int x = solve(1,n,0);
   cout<<x<<"\n";




  
 
 






 
#ifndef LOCAL_DEFINE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
