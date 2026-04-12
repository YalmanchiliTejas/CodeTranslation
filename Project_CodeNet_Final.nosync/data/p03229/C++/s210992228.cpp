#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i < m; i++)
#define ll long long int

using namespace std;

int main()
{
  int n;
  ll a[1000001];

  cin >> n;
  REP(i,n) {
    cin >> a[i];
  }
  sort(a,a+n);

  ll l = a[0], r = a[n-1];
  ll result = abs(r-l);
  int lp = 1, rp = n-2;
  while(lp <= rp) {
    int flg = 0;
    int tmp = abs(a[lp] - l);
    if(tmp < abs(a[lp] - r)) {
      tmp = abs(a[lp] - r);
      flg = 1;
    }
    if(tmp < abs(a[rp] - l)) {
      tmp = abs(a[rp] - l);
      flg = 2;
    }
    if (tmp < abs(a[rp] - r)) {
      tmp = abs(a[rp] - r);
      flg = 3;
    }


    result += tmp;
    switch (flg){
    case 0:
      l = a[lp];
      lp++;
      break;
    case 1:
      r = a[lp];
      lp++;
      break;
    case 2:
      l = a[rp];
      rp--;
      break;
    case 3:
      r = a[rp];
      rp--;
      break;
    default:
      break;
    }
  }
  cout << result << endl;

}
