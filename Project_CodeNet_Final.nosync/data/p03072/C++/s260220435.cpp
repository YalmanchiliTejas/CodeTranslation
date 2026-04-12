#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> H(N);
  int count = 1;
  
  for (int i = 0; i < N; i++){
    cin >> H.at(i);
  }
  
  int maxH = H.at(0);
  
  for (int i = 1; i < N; i++){    
    if (H.at(i) >= maxH){
      count++;
      maxH = H.at(i);
    }
  }
  
  cout << count << endl;
  
}