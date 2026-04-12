#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
#define int long long
#define MOD 1000000007
typedef pair<int,int> P;
typedef pair<int,P> PP;
int n,m,k;
int d[16];
int v[110][110];
int isd[110];

int dp[1<<16];

int dfs(int s){
  if(dp[s]!=-1)return dp[s];
  dp[s]=111111111;
  for(int i=0;i<k;i++){
    int t=0;
    for(int j=0;j<m;j++){
	 if(s>>j&1){
	   if(isd[v[d[j]][i]]>=0&&(t>>isd[v[d[j]][i]]&1)==0){
		t+=(1<<isd[v[d[j]][i]]);
	   }
	 }
    }
    if(s==t)continue;
    dp[s]=min(dp[s],dfs(t)+1);
  }
  return dp[s];
}

signed main(){
  cin>>n>>m>>k;
  fill_n(isd,100,-1);
  for(int i=0;i<m;i++){
    cin>>d[i];
    d[i]--;
    isd[d[i]]=i;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
	 cin>>v[i][j];
	 v[i][j]--;
    }
  }
  fill_n(dp,1<<16,-1);
  dp[0]=0;
  cout<<dfs((1<<m)-1)<<endl;
  return 0;
}

