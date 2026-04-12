/*siddharth goyal*/
#include<bits/stdc++.h>
using namespace std;
#define   pb              push_back
#define   REP(i,n)        for(i=1;i<=n;i++)
#define   FOR(i,a,b)      for(i=a;i<=b;i++)
#define   all(v)          v.begin(),v.end()
#define   F               first
#define   S               second
#define   vl              vector<LL>
#define   itr             ::iterator it
#define   lb              lower_bound
#define   ub              upper_bound
#define   LL              long long
#define   ULL             unsigned long long
LL n,i,j,ans = 0;
LL a[1000000] ; 
int main()
{   // Read the constraints,highlights,Time Limit,Test Cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL n ; 
    cin>>n ; 
    REP(i,n) cin>>a[i] ;
    vl V,V1,V2(n+3) ;  
    sort(a+1,a+1+n) ;
    for(i=n;i>n/2;i--) V.pb(a[i]) ; 
    LL p = 0; 
    for(i=1;i<=n/2;i++) V1.pb(a[i]) ;
    LL k = 0 ;  
    for(i=3;i<=n;i+=2)  V2[i] = V[k++] ;
    V2[1] = V[V.size()-1] ; 
    k = 0 ; 
    for(i=2;i<=n;i+=2)  V2[i] = V1[k++] ;
    for(i=2;i<=n;i++) p = p + abs(V2[i]-V2[i-1]) ; 
    ans = max(p,ans) ; 
    k = 0 ;
    if(n%2)
    {  V.clear() ; V1.clear() ; 
      for(i=n;i>n/2+1;i--) V.pb(a[i]) ; 
      for(i=1;i<=n/2+1;i++) V1.pb(a[i]) ;
      k = 0 ;  
      for(i=3;i<=n;i+=2) V2[i] = V1[k++] ;
      V2[1] = V1[V1.size()-1] ; 
      k = 0 ; 
      for(i=2;i<=n;i+=2) V2[i] = V[k++] ;  
      p = 0 ; 
      for(i=2;i<=n;i++) p = p + abs(V2[i]-V2[i-1]) ; 
      ans = max(p,ans) ; 
    }
    else
    { for(i=3;i<=n;i+=2)  V2[i] = V1[k++] ;
      k = 0 ; 
      V2[1] = V1[V1.size()-1] ; 
      for(i=2;i<=n;i+=2)  V2[i] = V[k++] ;
      p = 0 ;
      for(i=2;i<=n;i++) p = p + abs(V2[i]-V2[i-1]) ; 
      ans = max(p,ans) ; 
    }
    cout<<ans ;    

}
//Check for 0,1 and other corner cases.