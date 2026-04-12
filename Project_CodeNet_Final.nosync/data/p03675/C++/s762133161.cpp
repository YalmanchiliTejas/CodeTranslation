#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

const int MAXN = 2e5 + 10;

int n;
int a[MAXN];

stack <int> s;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  for (int i = n - 1; i >= 0; i -= 2)
    printf("%d ", a[i]);

  for (int i = n - 2; i >= 0; i -= 2)
    s.push(a[i]);

  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  printf("\n");

  return 0;
}

