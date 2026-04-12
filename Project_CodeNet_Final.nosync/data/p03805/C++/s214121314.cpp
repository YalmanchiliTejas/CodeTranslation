#include <bits/stdc++.h>
using namespace std;

#define PI 4*atan(1)
#define INF 1e8

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int> > g(N + 1, vector<int>(N + 1, 0));
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  vector<int> perm(N);
  for(int i = 0; i < N; i++){
    perm[i] = i + 1;
  }

  int cnt = 0;
  do{
    if(perm[0] != 1)continue;
    bool flag = true;
    for(int i = 0; i < N - 1; i++){
      if(g[perm[i]][perm[i + 1]] != 1)flag = false;
    }
    if(flag)cnt++;
  }while(next_permutation(perm.begin(), perm.end()));
  cout << cnt << endl;
}
