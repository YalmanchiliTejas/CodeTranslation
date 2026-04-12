#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin>>N>>M;
  vector<int> v;
  for(int i=0; i<N; i++)  v.push_back(i);

  vector<vector<bool>> graph(N, vector<bool>(N, false));
  for(int i=0; i<M; i++){
    int a, b;
    cin>>a>>b;
    graph[a-1][b-1]=true;  graph[b-1][a-1]=true;
  }

  int cnt = 0;
  do{
    bool check = true;
    for(int i=0; i<N; i++){
      if(v[0]!=0)  check = false;
      if(i<N-1){
        if(!graph[v[i]][v[i+1]])  check = false;
      }
    }
    if(check)  cnt++;
  }while(next_permutation(v.begin(), v.end()));

  cout<<cnt<<endl;
  return 0;
}
