#include <bits/stdc++.h>
using namespace std;

int main() {
  int Aprice,Bprice,ABprice,Aneed,Bneed;
  cin >> Aprice >> Bprice >> ABprice >> Aneed >> Bneed;

  int Anum = Aneed;
  int Bnum = Bneed;
  int ABnum = 0;
  int ans = INT_MAX;

  while (true) {
    int total = Aprice*Anum +
      Bprice*Bnum +
      ABprice*ABnum;

    ans = min(ans, total);

    if (Anum == 0 && Bnum == 0) {
      break;
    }

    Anum != 0 and --Anum;
    Bnum != 0 and --Bnum;
    ABnum += 2;
  }

  cout << ans << endl;
}
