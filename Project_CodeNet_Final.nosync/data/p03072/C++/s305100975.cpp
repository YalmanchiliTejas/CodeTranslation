#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++) {
    cin >> H.at(i);
  }
  
  
  int count = 1;
  
  for (int i=1; i<N; i++) {
    bool flag = true;
    for (int j=0; j<i; j++) {
      if (H[j] > H[i]) flag = false;
    }
    if (flag) count++;
  }
  
  cout << count << endl;

}