#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> dark(m);
  vector<int> isDark(n,-1);
  for(int i=0;i<m;i++){
    int d;
    cin>>d;
    d--;
    isDark[d]=i;
    dark[i]=d;
  }

  vector<vector<int>> v(n,vector<int>(k));
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
      int val;
      cin>>val;
      val--;
      v[i][j]=val;
    }
  }

  vector<vector<int>> edge(1<<m,vector<int>(k));
  for(int i=0;i<(1<<m);i++){
    for(int j=0;j<k;j++){
      int to=0;
      for(int r=0;r<m;r++){
	if((i&(1<<r)) && isDark[v[dark[r]][j]]!=-1){
	  to|=(1<<isDark[v[dark[r]][j]]);
		      
	}
      }
      edge[i][j]=to;

    }
  }

  const int INF=1e9;
  vector<int> d(1<<m,INF);
  queue<pair<int,int>> que;
  d[(1<<m)-1]=0;
  que.push({(1<<m)-1,0});
  while(!que.empty()){
    auto p=que.front();
    que.pop();
    if(p.first==0){
      cout<<p.second<<endl;
      return 0;
    }
    for(int i=0;i<edge[p.first].size();i++){
      if(d[edge[p.first][i]]>=INF){
	d[edge[p.first][i]]=p.second+1;
	que.push({edge[p.first][i],p.second+1});
      }
		 
    }
  }  
			       
  return 0;
}