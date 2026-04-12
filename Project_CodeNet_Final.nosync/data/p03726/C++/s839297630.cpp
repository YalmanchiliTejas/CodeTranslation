#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> v[100000];
  for(int i=0; i<n-1; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int d[100000];
  fill(d, d+n, -1);
  d[0]=0;
  queue<int> que;
  que.push(0);
  while(!que.empty()){
    int x=que.front();
    que.pop();
    for(int i=0; i<v[x].size(); i++){
      if(d[v[x][i]]<0){
        d[v[x][i]]=d[x]+1;
        que.push(v[x][i]);
      }
    }
  }
  vector<P> dist;
  for(int i=0; i<n; i++){
    dist.push_back(P(d[i], i));
  }
  sort(dist.begin(), dist.end(), greater<P>());
  bool used[100000]={};
  bool e=0;
  for(int i=0; i<n; i++){
    int x=dist[i].second;
    if(used[x]==1) continue;
    bool e1=0;
    used[x]=1;
    for(int j=0; j<v[x].size(); j++){
      int y=v[x][j];
      if(d[y]>d[x]) continue;
      if(used[y]==0){
        e1=1;
        used[y]=1;
        break;
      }
    }
    if(e1==0){
      e=1;
      break;
    }
  }
  if(e==1){
    printf("First\n");
  }else{
    printf("Second\n");
  }
	return 0;
}
