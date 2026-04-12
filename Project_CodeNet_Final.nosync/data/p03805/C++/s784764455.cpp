#include <bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
 
int main() {
  int N,M;
  cin >> N >> M;
  Graph G(N);
  for (int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  vector<int> point(N);
  for (int i=0;i<N;i++){
    point[i]=i;
  }
  int ans=0;
  do {
    bool path=true;
    for (int i=0;i<N-1;i++){
      bool path2=true;
      for (int j=0;j<G[point[i]].size();j++){
        if (G[point[i]][j]==point[i+1]){
          path2=false;
        }
      }
      if (path2){
        path=false;
      }
    }
    if (path){
      ans++;
    }
  } while(next_permutation(point.begin()+1,point.end()));
  cout << ans << endl;
}