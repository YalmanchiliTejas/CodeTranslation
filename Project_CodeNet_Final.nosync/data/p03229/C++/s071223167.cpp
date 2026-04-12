#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))

#define rep(i,n) for(auto i=0; i<(n); i++)

const int mod = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n;
  cin >> n;

  vector<long> a(n);
  fillLong(a, n);

  sortv(a);
  int idxl = 1;
  int idxr = n-1;
  int left = a[0];
  int right = a[0];

  int mode = 0;
  long res = 0;

  while(idxl <= idxr) {
    if (mode == 0) {
      res += a[idxr] - left;
      left = a[idxr];
      idxr--;
    } else if (mode == 1) {
      res += a[idxr] - right;
      right = a[idxr];
      idxr--;
    } else if (mode == 2) {
      res += left - a[idxl];
      left = a[idxl];
      idxl++;
    } else if (mode == 3) {
      res += right - a[idxl];
      right = a[idxl];
      idxl++;
    } 
    mode = (mode+1)%4;
  }

  long res2 = 0;
  idxl = 0;
  idxr = n-2;
  left = a[n-1];
  right = a[n-1];
  mode = 2;

  while(idxl <= idxr) {
    if (mode == 0) {
      res2 += a[idxr] - left;
      left = a[idxr];
      idxr--;
    } else if (mode == 1) {
      res2 += a[idxr] - right;
      right = a[idxr];
      idxr--;
    } else if (mode == 2) {
      res2 += left - a[idxl];
      left = a[idxl];
      idxl++;
    } else if (mode == 3) {
      res2 += right - a[idxl];
      right = a[idxl];
      idxl++;
    } 
    mode = (mode+1)%4;
  }

  cout << max(res, res2) << endl;
}
