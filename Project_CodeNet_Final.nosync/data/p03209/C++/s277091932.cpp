#include <iostream>

using namespace std;

long long  all[51];
long long  pn[51];
long long  ans = 0;

long long calc(long long  x, int  n) {
  //cout << n << " " << x << "\n";
  if (x == all[n]) {
    ans += pn[n];
    return 0;
  }
  if (x == (all[n - 1] + 2 )) {
    ans += pn[n - 1] + 1;
    return 0;
  }
  if (x == 1) {
    return 0;
  }
  if (x > (all[n - 1]) + 2 ) {
    ans += pn[n - 1] + 1;
    calc(x - (all[n - 1] + 2) , n - 1);
  } else {
    calc(x - 1, n - 1);
  }


}

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  all[0] = 1;
  pn[0] = 1;
  int n;
  long long  x;
  cin >> n;
  cin >>  x ;


  for (int i = 1; i <= n; i++) {
    all[i] = 2 * all[i - 1] + 3;
    pn[i] = 2 * pn[i - 1] + 1;
  }
  /*
    for(int i = 0; i <= n; i++) {
      cout << all[i] << "\n";
    }
    for(int i = 0; i <= n; i++) {
      cout << pn[i] << "\n";

    }
    */
  calc(x, n);

  cout << ans << "\n";
  return 0;
}