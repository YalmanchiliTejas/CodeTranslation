#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> d(m);
  map<int,int> dark_map;
  for(int i=0;i<m;i++){
    cin>>d[i];
    d[i]--;
    dark_map[d[i]]=i;
  }
  vector<vector<int>> v(n,vector<int>(k));
  for(int i=0;i<n;i++)
    for(int j=0;j<k;j++){
      cin>>v[i][j];
      v[i][j]--;
    }
  vector<vector<int>> v2(m);
  for(int i=0;i<m;i++){
    v2[i]=v[d[i]];
  }
  const int INF=1e9;
  vector<int> dp(1<<m,INF);
  int first_p=(1<<m)-1;
  dp[first_p]=0;
  pair<int,int> state=make_pair(0,first_p);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
  que.push(state);

  while(!que.empty()){
    state=que.top();
    que.pop();
    int p=state.second;
    int sc=state.first;
    if(dp[p]<sc) continue;

    for(int i=0;i<k;i++){
      int top=0;
      for(int j=0;j<m;j++){
	if(p & (1<<j)){
	  if(dark_map.count(v2[j][i])){
	    top|=(1<<(dark_map[v2[j][i]]));
	  }
	}
      }
      if(dp[top]>sc+1){
	dp[top]=sc+1;
	que.push(make_pair(sc+1,top));
      }
    }
  }
  cout<<dp[0]<<endl;
  return 0;
}