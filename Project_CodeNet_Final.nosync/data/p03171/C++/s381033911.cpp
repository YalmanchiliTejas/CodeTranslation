#include <cstdio>
#include <algorithm>

using namespace std;

using llint = long long;

const int MAXN = 3e3+3;

int n, a[MAXN];
llint mem[MAXN][MAXN];
bool solved[MAXN][MAXN];

llint dp(int l, int r, bool t) {
  if (l > r) return 0;
  
  llint &ret = mem[l][r];
  if (solved[l][r]) return ret;
  solved[l][r] = 1;

  ret = t == 0 ? 
    max(dp(l+1, r, !t)+a[l], dp(l, r-1, !t)+a[r]) :
    min(dp(l+1, r, !t)-a[l], dp(l, r-1, !t)-a[r]);
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }

  printf("%lld\n", dp(0, n-1, 0));
  return 0;
}
