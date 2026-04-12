
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 200000;
int N;
int a[MAX_N+1];

int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> a[i];
  
  if (N == 1) {
    printf("%d\n", a[1]);
    return 0;
  }

  if (N%2 == 0) {
    for (int i = N; i > 0; i -= 2) {
      printf("%d ", a[i]);
    }
    for (int i = 1; i <= N; i += 2) {
      printf("%d%c", a[i], i == N-1 ? '\n' : ' ');
    }
  } else {
    for (int i = N; i > 0; i -= 2) {
      printf("%d ", a[i]);
    }
    for (int i = 2; i <= N; i += 2) {
      printf("%d%c", a[i], i == N-1 ? '\n' : ' ');
    }
  }

  return 0;
}
