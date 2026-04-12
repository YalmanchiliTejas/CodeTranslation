#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++) cin >> V[i];
  int maior = 0, C = 0;
  for (int i = 0; i < N; i++){
    if (V[i] >= maior){
      maior = max(maior, V[i]);
      C++;
    }
  }
  cout << C << '\n';
}