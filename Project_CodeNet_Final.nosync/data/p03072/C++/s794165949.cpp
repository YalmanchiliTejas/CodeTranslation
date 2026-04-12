#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  int a = 0;
  int count = 0;
  for(int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  for(int i = 0; i < N; i++) {
    if(i == 0) {
      a = H.at(0);
    }
    else {
      a = max(H.at(i),a);
    }
    if(H.at(i) >= a) {
      count++;
    }
  }
  cout << count << endl;
}
