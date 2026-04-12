#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  long long sum = 0;
  rep(i, N)
  {
    cin >> A[i];
    sum += A[i];
  }
  int MOD = 1000000007;

  long long sum2 = 0;
  rep(i, N)
  {
    sum -= A[i];
    long long tmp_sum = sum % MOD;
    long long tmp = (tmp_sum * A[i]) % MOD;
    sum2 += tmp;
    sum2 %= MOD;
  }

  cout << sum2 << endl;

  return 0;
}
