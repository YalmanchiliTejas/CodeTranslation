#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <climits>
#include <functional>

#define REP(i,n) for(int i = 0;i < n;i++)

using namespace std;
typedef long long ll;
const int INF = INT_MAX / 4;

const int max_n = 1e3;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int a[N];
  REP(i, N) cin >> a[i];

  // if (N == 1) {
  //   cout << a[0];
  //   return 0;
  // }

  int i;
  for(i = N-1;i >= 0;i -= 2) {
    cout << a[i];
    if (i > 1) cout << " ";
  }
  if (N % 2) i = 1;
  else i = 0;
  for(;i < N;i += 2) {
    cout << " " << a[i];
  }

  cout << "\n";
  return 0;
}
