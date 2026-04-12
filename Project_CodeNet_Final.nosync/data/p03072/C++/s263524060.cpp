#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int Max = 0;
  int count = 0;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) > Max || A.at(i) == Max) {
      Max = A.at(i);
      count++;
    }
  }
  
  cout << count << endl;
  
}
