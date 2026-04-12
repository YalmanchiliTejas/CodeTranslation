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
  string S;
  int K;
  cin >> N >> S >> K;
  char c = S[K - 1];
  REP(i, N)
  {
    if (S[i] != c)
      cout << "*";
    else
      cout << S[i];
  }
  cout << '\n';
  return 0;
}