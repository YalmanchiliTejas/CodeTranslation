#include<cstdio>
#include<algorithm>
#include<queue>
#include<list>

using namespace std;

/*
n m
a1 b1
...
aM bM

n: vertex
m: edge
*/

int n, m;
int main(){
  scanf("%d %d", &n, &m);
  list<pair<int, int>> edge;
  for(int i = 0; i < m; i++){
    int a,b;
    scanf("%d %d", &a, &b);
    pair<int, int> p(a, b);
    edge.push_front(p);
  }

  queue<list<int>> que;
  list<int> ini;
  ini.push_front(1);
  que.push(ini);

  int ans = 0;
  while(!que.empty()){
    list<int> path = que.front();
    que.pop();

    if(path.size() >= n){
      ans++;
      continue;
    }

    int back = path.back();
    //printf("back = %d\n", back);

    for(int i = 1; i <= n; i++){
      if(find(path.begin(), path.end(), i) != path.end()) continue;

      //printf("i = %d\n", i);

      bool f = false;
      for( auto &e : edge ){
        if((e.first == back && e.second == i) || (e.first == i && e.second == back))
          f = true;
      }
      if(!f) continue;

      list<int> path1 = path;
      path1.push_back(i);
      que.push(path1);
    }
  }

  printf("%d\n", ans);
  return 0;
}

