#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main()
{
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N)
  cin >> A[i];
  sort(ALL(A));
  reverse(ALL(A));
  ll sum1 = 0, sum2 = 0;
  // A1 > A2 < A3 > ...のパターン
  int pos = 0;
  REP(i, (N - 2) / 2)
  sum1 += (2 * A[pos++]);
  sum1 += A[pos++];
  sum1 += (N % 2 == 0) ? -A[pos++] : A[pos++];
  REP(i, (N - 1) / 2)
  sum1 -= (2 * A[pos++]);
  // A1 < A2 > A3 < ...のパターン
  pos = 0;
  REP(i, (N - 1) / 2)
  sum2 += (2 * A[pos++]);
  sum2 += (N % 2 == 0) ? A[pos++] : -A[pos++];
  sum2 -= A[pos++];
  REP(i, (N - 2) / 2)
  sum2 -= (2 * A[pos++]);
  cout << max(sum1, sum2) << endl;
  return 0;
}