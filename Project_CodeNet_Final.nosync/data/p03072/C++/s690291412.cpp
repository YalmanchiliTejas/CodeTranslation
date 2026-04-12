#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> Hs(N);
  for (int i = 0; i < N; i++) { cin >> Hs.at(i); }
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j >= 0; j--) {
      if (Hs.at(j) > Hs.at(i)) { break; }
      if (j == 0) { count++; }
    }
  }
  cout << count << endl;
}