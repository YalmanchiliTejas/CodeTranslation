#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  vector<int> b(M);
  for (int i = 0; i < M; i++) cin >> a.at(i) >> b.at(i);
  vector<int> n(N);
  for (int i = 0; i < N; i++) n.at(i) = i + 1;
  
  int ans = 0;
  sort(n.begin(), n.end());
  do {
    if (n.at(0) != 1) continue;
    
    bool check = true;
    for (int i = 1; i < N; i++){
      int aa = n.at(i - 1);
      int bb = n.at(i);
      bool check2 = false;
      for (int i = 0; i < M; i++){
        if (a.at(i) == aa && b.at(i) == bb){
          check2 = true;
          break;
        }
        else if (a.at(i) == bb && b.at(i) == aa){
          check2 = true;
          break;
        }
      }
      if (!check2){
        check = false;
        break;
      }
    }
    if (check) ans++;
  } while (next_permutation(n.begin(), n.end()));
  
  cout << ans << endl;
}
