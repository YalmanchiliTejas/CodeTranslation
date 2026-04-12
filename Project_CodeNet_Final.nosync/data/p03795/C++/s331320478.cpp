#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
    
    if (N < 15)
      cout << 800 * N << endl;
    if (15 <= N)
      cout << (800 * N) - 200 * (N / 15) << endl;
}