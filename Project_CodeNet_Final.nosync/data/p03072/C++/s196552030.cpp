#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int Hs[N];
  for(int i=0; i < N; i++){
      cin >> Hs[i];
  }
  int ans = 1;
  for(int i=1; i < N; i++){
      ans++;
      for(int j=0; j < i; j++){
          if(Hs[j] > Hs[i]){
              ans--;
              break;
          }
      }
  }
  cout << ans << "\n";
  return 0;
}