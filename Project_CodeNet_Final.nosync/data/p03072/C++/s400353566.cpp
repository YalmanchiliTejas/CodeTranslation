#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int count = 0;
  
  vector<int>H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int M = H.at(0);
  
  for (int i = 0; i < N; i++) {
    if (H.at(i) >= M){
      count++;
      M = H.at(i);
    }
  }
  cout << count << endl;
}