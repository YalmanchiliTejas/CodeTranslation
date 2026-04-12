#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int path=0;
int N,M;
void dfs(multimap<int,int> mp, vector<int> visited, int state){
  visited[state-1] = 1;
  for(int i=0; i < N; i++){
    if(visited[i] == 0) break;
    if(i == N-1) path += 1;
  }
  auto r = mp.equal_range(state);
  for(auto itr=r.first; itr != r.second; itr++){
    if(visited[(itr->second)-1] == 0)
      dfs(mp, visited, itr->second);
  }
}
int main()
{
  cin >> N >> M;
  vector<int> visited(N);
  for(int i=0; i < N; i++)
    visited[i] = 0;
  multimap<int, int> mp;
  for(int i=0; i < M; i++){
    int fst,snd;
    cin >> fst >> snd;
    mp.insert(make_pair(fst,snd));
    mp.insert(make_pair(snd,fst));
  }
  dfs(mp,visited,1);
  cout << path << endl;
  return 0;
}
