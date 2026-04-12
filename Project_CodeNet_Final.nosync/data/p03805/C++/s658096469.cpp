#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define MP make_pair


int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

bool graph[8][8];
int n, m;

int dfs(int x, bool visited[], int num_visited){
  if(num_visited == n){
    return 1;
  }

  int res = 0;
  REP(i, n){
    if(graph[x][i] == true && visited[i] == false){     
      bool next_visited[8];
      memcpy(next_visited, visited, sizeof(bool) * 8);
      next_visited[i] = true;
      res += dfs(i, next_visited, num_visited + 1);
    }
  }
  return res;
}

int main(){

  scanf("%d %d", &n, &m);
  REP(i,m){
    int t1, t2;
    scanf("%d %d", &t1, &t2);
    graph[t1 - 1][t2 - 1] = graph[t2 - 1][t1 - 1] = true;
  }

  bool visited[8] = {};
  visited[0] = true;
  printf("%d\n", dfs(0, visited, 1));

  return 0;
}

