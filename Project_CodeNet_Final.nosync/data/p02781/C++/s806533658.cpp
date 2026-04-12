#include <bits/stdc++.h>

using namespace std;

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

int64_t comb(int64_t n, int64_t k)
{
  int64_t p = 1, q = 1;
  N_TIMES(i, k) {
    p *= (n - i);
    q *= (i + 1);
  }
  return p / q;
}

int64_t power(int64_t x, int64_t y)
{
  if (y <= 1) { return (y == 0) ? 1 : x; }

  int64_t w = power(x, y >> 1);
  int64_t z = w * w;
  if ((y & 1) == 1) { z *= x; }

  return z;
}

int64_t dfs(const vector<int64_t> &N, int64_t K, int64_t L, int64_t i, int64_t k)
{
  if (k < 0) { return 0; }

  if (i == L) { return (k == 0) ? 1 : 0; }

  int64_t sum = 0;

  if (N[i] == 0) {
    sum += dfs(N, K, L, i + 1, k);
  } else if (N[i] == 1) {
    sum += dfs(N, K, L, i + 1, k - 1);

    int64_t remain_len = (L - 1) - i;
    if (remain_len >= k) {
      sum += comb(remain_len, k) * power(9, k);
    }
  } else {
    sum += dfs(N, K, L, i + 1, k - 1);

    int64_t remain_len = (L - 1) - i;
    int64_t p = N[i] - 1;

    if (k >= 1 && remain_len >= k - 1) {
      sum += p * comb(remain_len, (k - 1)) * power(9, k - 1);
    }

    if (k >= 0 && remain_len >= k) {
      sum += comb(remain_len, k) * power(9, k);
    }
  }
  
  return sum;
}

int main()
{
  string S;
  cin >> S;
  
  int64_t L = S.size();

  vector<int64_t> N(L);
  N_TIMES(i, L) { N[i] = S[i] - '0'; }

  int64_t K;
  cin >> K;

  int64_t ans = dfs(N, K, L, 0, K);
  cout << ans << endl;

  return 0;
}