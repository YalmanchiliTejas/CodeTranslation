#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
int a,b,c, x,y ;
cin >>a>>b>>c>>x>>y ;
int ans=0 ;
if(x>=y)
ans=c*y*2+a*(x-y) ;
else
ans =c*x*2+b*(y-x) ;
int zen= c*2*max(x,y) ;
cout <<min(zen,min((a*x+b*y),ans )) <<endl ;
     return 0;
}