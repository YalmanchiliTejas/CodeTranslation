#include<bits/stdc++.h>
using namespace std;
const int maxN=258;
int dp[maxN][8];
vector<int>g[8];
bool mrk[maxN][8];
int n,m;
int main(){
  cin>>n>>m;
  while(m--){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dp[1][0]=1;
  for(int mask=3;mask<(1<<n);mask++){
    vector<int>v;
    for(int i=0;i<n;i++){
      if(mask&(1<<i))
	mrk[mask][i]=true;
    }
    for(int i=0;i<n;i++){
      if(mask&(1<<i))
	for(int j=0;j<g[i].size();j++){
	  if(mrk[mask][g[i][j]])
	    dp[mask][i]+=dp[mask-(1<<i)][g[i][j]];
	}
    }
  }
  int ans=0;
  for(int i=0;i<n;i++)ans+=dp[(1<<n)-1][i];
  cout<<ans<<endl;
}
