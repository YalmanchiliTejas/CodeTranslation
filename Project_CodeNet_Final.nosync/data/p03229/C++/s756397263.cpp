#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }
  long long ans = 0;
  if (N % 2 == 0)
  {
    RSORT(A);
    rep(i, N / 2 - 1)
    {
      ans += 2 * A[i];
    }
    ans += A[N / 2 - 1];
    SORT(A);
    rep(i, N / 2 - 1)
    {
      ans -= 2 * A[i];
    }
    ans -= A[N / 2 - 1];
  }
  else
  {
    long long score1 = 0, score2 = 0;
    RSORT(A);
    rep(i, (N - 1) / 2)
    {
      score1 += 2 * A[i];
    }
    SORT(A);
    rep(i, (N + 1) / 2 - 2)
    {
      score1 -= 2 * A[i];
    }
    score1 -= A[(N + 1) / 2 - 2];
    score1 -= A[(N + 1) / 2 - 1];

    SORT(A);
    rep(i, (N - 1) / 2)
    {
      score2 -= 2 * A[i];
    }
    RSORT(A);
    rep(i, (N + 1) / 2 - 2)
    {
      score2 += 2 * A[i];
    }
    score2 += A[(N + 1) / 2 - 2];
    score2 += A[(N + 1) / 2 - 1];
    ans = max(score1, score2);
  }
  cout << ans << endl;
  return 0;
}