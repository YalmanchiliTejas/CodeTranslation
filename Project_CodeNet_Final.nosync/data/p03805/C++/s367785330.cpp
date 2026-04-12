#include<cstdio>
#include<algorithm>
#include<queue>
#include<list>

using namespace std;

typedef list<int> Path;
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

  bool connected[n+1][n+1];
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      connected[i][j] = false;
  
  for(int i = 0; i < m; i++){
    int a,b;
    scanf("%d %d", &a, &b);
    connected[a][b] = true;
    connected[b][a] = true;    
  }

  queue<Path> que;
  Path ini;
  ini.push_front(1);
  que.push(ini);

  int ans = 0;
  while(!que.empty()){
    Path path = que.front();
    que.pop();

    if(path.size() >= n){
      ans++;
      continue;
    }

    int back = path.back();
    //printf("back = %d\n", back);

    for(int i = 1; i <= n; i++){
      // i in path -> continue
      if(find(path.begin(), path.end(), i) != path.end()) continue;

      //printf("i = %d\n", i);

      if(connected[back][i]){
        Path path1 = path;
        path1.push_back(i);
        que.push(path1);
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}

