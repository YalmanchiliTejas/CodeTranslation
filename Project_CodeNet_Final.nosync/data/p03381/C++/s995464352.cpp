#include <bits/stdc++.h>
using namespace std;

int main(void){
 int N;
  cin >> N;
  vector<int> X(N);
  vector<int> S(N);
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    X[i] = temp;
    S[i] = temp;
  }
  sort(S.begin(), S.end());
  int center = S[N / 2 - 1];
  int cp = S[N / 2];
  for(int i = 0; i < N; i++){
    if(X[i] <= center){
      cout << cp << endl;
    }
    else cout << center << endl;
  }
  
  
  return 0;
}