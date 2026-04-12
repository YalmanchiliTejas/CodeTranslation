#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 1;
  int max;
  cin >> max;
  for(int i = 1; i < N; i++) {
    int h;
    cin >> h;
    if(h >= max) {
      count++;
      max = h;
    }
  }
  cout << count << endl;
}