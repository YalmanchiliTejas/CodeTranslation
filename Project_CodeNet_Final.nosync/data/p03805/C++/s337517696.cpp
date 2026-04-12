#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for(int i=0; i<M; i++) {
    cin >> a.at(i) >> b.at(i);
    a.at(i)--; b.at(i)--;
  }
  
  vector<vector<bool>> ok(N, vector<bool>(N));
  for(int i=0; i<M; i++) {
    ok.at(a.at(i)).at(b.at(i)) = true;
    ok.at(b.at(i)).at(a.at(i)) = true;
  }
  
  vector<int> perm(N-1);
  for(int i=0; i<N-1; i++) perm.at(i) = i+1;
  
  int ans = 0;
  do {
    bool x = true;
    int v = 0;
    for(int i=0; i<N-1; i++) {
      if(!ok.at(v).at(perm.at(i))) x = false;
      v = perm.at(i);
    }
    if(x) ans++;
  } while (next_permutation(perm.begin(), perm.end()));
  
  cout << ans << endl;
  
}