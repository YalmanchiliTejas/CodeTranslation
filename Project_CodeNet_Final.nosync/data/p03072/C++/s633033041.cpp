#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  vector<int> vec(N);
  
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  
  int count = 1;
  bool x = true;
  
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < i; j++) {
      if(vec.at(i) < vec.at(j)) {
        x = false;
        break;
      }
    }
    if(x) {
      count++;
    }
    x = true;
  }
  
  cout << count << endl;
  
}