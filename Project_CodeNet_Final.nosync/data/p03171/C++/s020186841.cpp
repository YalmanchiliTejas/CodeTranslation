#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const Int MAX = 3030;
const Int INF = 1e15;
Int n;
Int a[MAX];
Int dp[MAX][MAX],vi[MAX][MAX];
Int dfs(Int k,Int l,Int r){
  Int &res=dp[l][r];
  if(vi[l][r]) return res;
  vi[l][r]=1;
  if(l==r) return res=0;
  if(k==0){
    res=-INF;
    chmax(res,dfs(!k,l+1,r)+a[l]);
    chmax(res,dfs(!k,l,r-1)+a[r-1]);    
  }
  if(k==1){
    res=+INF;
    chmin(res,dfs(!k,l+1,r)-a[l]);
    chmin(res,dfs(!k,l,r-1)-a[r-1]);    
  }
  return res;
}

signed main(){
  cin>>n;
  for(Int i=0;i<n;i++) cin>>a[i];
  memset(vi,0,sizeof(vi));
  cout<<dfs(0,0,n)<<endl;  
  return 0;
}
