#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  bool path[N][N];
  memset(path,false,sizeof(path));
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a][b]=true;
    path[b][a]=true;
  }
  int vertex[N];
  for (int i=0; i<N; i++) {
    vertex[i]=i;
  }
  int ans=0;
  do {
    if (vertex[0]!=0) {
      continue;
    }
    for (int i=0; i<N-1; i++) {
      if (!path[vertex[i]][vertex[i+1]]) {
        break;
      }
      if (i==N-2) {
        ans++;
      }
    }
  } while (next_permutation(vertex,vertex+N));
  cout << ans << endl;
  return 0;
}

