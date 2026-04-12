#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int n_subsets = pow(2, n);

  for (int i = 0; i < n_subsets; i++) {
    bitset<18> bs(i);
    cout << i << ":";
    for (int j = 0; j < 18; j++) {
      if (bs.test(j)) {
        cout << " " << j;
      }
    }
    cout << endl;
  }
}


