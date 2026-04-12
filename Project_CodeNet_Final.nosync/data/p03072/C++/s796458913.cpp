#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, i, count = 0, maxh = 0;
  cin >> N;
  
  vector<int> H(N);
  for(i = 0; i < N; i++){
    cin >> H.at(i);
  }
  
  for(i = 0; i < N; i++){
    if(H.at(i) >= maxh){
      maxh = H.at(i);
      count++;
    }
  }
  
  cout << count << endl;
}
