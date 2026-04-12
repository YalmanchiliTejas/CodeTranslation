#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int graph[M][2];
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    graph[i][0]=a;
    graph[i][1]=b;
  }
  vector<int> v(N);
  iota(v.begin(),v.end(),1);
  int ans=0;
  do{
    if(v.at(0)!=1) continue;
    int cnt=0;
    for(int i=0; i<N-1; i++){
      for(int j=0; j<M; j++){
        if(graph[j][0]==v.at(i) && graph[j][1]==v.at(i+1) || graph[j][0]==v.at(i+1) && graph[j][1]==v.at(i)) cnt++;
      }
    }
    if(cnt==N-1) ans++;
  }while(next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}