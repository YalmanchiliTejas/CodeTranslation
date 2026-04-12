#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 200005

int N, a[MAXN], b[MAXN];
int main() {
  cin >> N;
  REP(i,0,N) scanf("%d", a+i);
  int fi = 0, bi = N-1;
  for (int i=N-1;i>=0;i--) {
    if ((N-1-i)&1) b[bi--] = a[i];
    else b[fi++] = a[i];
  }
  REP(i,0,N) printf("%d ", b[i]);
  return 0;
}
