/*siddharth goyal*/
#include<bits/stdc++.h>
using namespace std;
#define   pb              push_back
#define   REP(i,n)        for(int i=1;i<=n;i++)
#define   FOR(i,a,b)      for(int i=a;i<=b;i++)
#define   all(v)          v.begin(),v.end()
#define   F               first
#define   S               second
#define   vl              vector<LL>
#define   itr             ::iterator it
#define   lb              lower_bound
#define   ub              upper_bound
#define   LL              long long
#define   ULL             unsigned long long
#define   ret             return 
#define   sz(x)           (LL)x.size()
LL n,i,j,ans = 0;
LL a[1000000] ; 
LL dp[3000+2][3000+2][3] ; 
LL f(LL start,LL end,LL chance)
{  if(start>end or start>n or end>n) ret 0 ; 
   if(dp[start][end][chance]!=-1) ret dp[start][end][chance] ; 
   if(chance==1)
     ret dp[start][end][chance] = max(a[start] + f(start+1,end,2),a[end] + f(start,end-1,2)) ; 
   else 
     ret dp[start][end][chance] = min(f(start+1,end,1) - a[start],f(start,end-1,1) - a[end]) ;  
   
}
int main()
{   // Read the constraints,highlights,Time Limit,Test Cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; 
    memset(dp,-1,sizeof(dp)) ; 
    REP(i,n) cin>>a[i] ; 
    cout<<f(1,n,1)<<endl ; 
}
//Check for 0,1 and other corner cases.