#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int S = N * 800;
  
  if (N >= 15) {
    cout << S - ((N / 15) * 200) << endl;
  } else {
    cout << S << endl;
  }
}
