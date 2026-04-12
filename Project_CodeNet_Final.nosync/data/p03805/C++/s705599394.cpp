#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<bool>> V(N,vector<bool>(N,false));
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    V[a][b] = true;
    V[b][a] = true;
  }
  
  vector<int> P(N-1);
  for(int i=0;i<N-1;i++) P[i] = i+1;
  int ans=0;
  do{
    bool ok = true;
    if(V[0][P[0]]==false) ok = false;
    for(int i=1;i<N-1;i++){
      if(V[P[i-1]][P[i]]==false) ok = false;
    }
    if(ok) ans++;
  }while(next_permutation(P.begin(),P.end()));
  
  cout << ans << endl;
  return 0;
}
