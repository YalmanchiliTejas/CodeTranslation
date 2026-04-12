#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
#define fin {cout<<"First"<<endl;return 0;}
//template

//main
signed main(){
  int N;cin>>N;
  std::vector<int> edge[N];
  for(int i=0;i<N-1;i++){
    int a,b;cin>>a>>b;a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  std::vector<int> v(N);
  for(int i=0;i<N;i++)v[i]=edge[i].size();
  queue<int> que;
  for(int i=0;i<N;i++)if(v[i]==1)que.push(edge[i][0]);
  int turn=0;
  std::vector<int> used(N,0);
  while(que.size()){
    int p=que.front();que.pop();
    turn++;
    if(used[p])continue;used[p]++;
    //cout<<p<<endl;
    for(int q:edge[p]){
      v[q]--;
      if(v[q]==0)turn--;
      if(v[q]==1){
        for(int i:edge[q])if(used[i]==0)que.push(i);
      }
    }
    if(turn<0)fin;
  }
  cout<<"Second"<<endl;
}
