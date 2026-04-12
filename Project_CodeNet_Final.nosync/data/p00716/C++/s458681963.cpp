#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int amount, years, n;
    cin >> amount >> years >> n;
    int ans = 0;
    for (int j = 0; j < n; j++) {
      int b, charge, total = 0;
      double rate;
      cin >> b >> rate >> charge;
      int balance = amount;
      int interest;
      for (int k = 0; k < years; k++) {
        interest = balance * rate;
        balance += b * interest - charge;
        total += interest;
      }
      ans = max(ans, !b * total + balance);
    }
    cout << ans << endl;
  }
}

