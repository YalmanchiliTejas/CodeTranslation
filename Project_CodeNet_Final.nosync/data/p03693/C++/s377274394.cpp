#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long LL;
#define REP(i,N) for (int i=0; i<N; i++)

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  if ((10*g + b) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}