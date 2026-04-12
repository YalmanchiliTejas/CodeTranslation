#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>//pair
#include<cmath>//abs,sqrt
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int INF=1e+9;
const ll INFLL=1e+17;
int n;
ll a[3010];
ll dp[3010][3010];
ll rec(int i,int j){
  if(dp[i][j]!=-INFLL) return dp[i][j];
  if(i==j){
    if((n+1)%2) return -a[i];
    else return a[i];
  }
  ll res;
  if((n-(j-i))%2){
    res=max(rec(i,j-1)+a[j],rec(i+1,j)+a[i]);
  }
  else{
    res=min(rec(i,j-1)-a[j],rec(i+1,j)-a[i]);
  }
  return dp[i][j]=res;
}


int main(){
  cin>>n;
  rep(i,n) cin>>a[i];
  rep(i,n){
    rep(j,n){
      dp[i][j]=-INFLL;
    }
  }
  ll res=rec(0,n-1);
  prin(res);

  


  return 0;
}
