#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <deque>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

// #define FL fflush(stdout)

#define MOD 1000000007
#define INF 2000000000
#define maxn 200010

int GLL(LL& x) {
  return scanf("%lld", &x);
}

int GI(int& x) {
  return scanf("%d", &x);
}

int n;
LL a[maxn];
deque<LL> d;

int main() {
  GI(n);
  FORN(i, n) GLL(a[i]);

  bool front = true;
  FORN(i, n) {
    if (front) d.push_front(a[i]);
    else d.push_back(a[i]);

    front = !front;
  }

  if (n%2) {
    for (auto dd : d) {
      printf("%lld ", dd);
    }
  } else {
    for (auto it = d.rbegin(); it != d.rend(); it++) {
      printf("%lld ", *it);
    }
  }
  printf("\n");
    
  return 0;
}