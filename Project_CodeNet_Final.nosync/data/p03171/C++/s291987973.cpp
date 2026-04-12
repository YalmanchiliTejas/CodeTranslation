#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
 
using namespace std;
 
int N;
vector<long long> v;
vector<vector<long long>> dp; 
long long LIM = std::numeric_limits<long long>::min();
 
long long deque(long long i, long long j)
{
  long long c = (N - j - i) % 2 == 0 ? 1 : -1; 
 
  if (i+1 == j) return v[i] * c;
  if (dp[i+1][j] == LIM) dp[i+1][j] = deque(i+1, j); 
  if (dp[i][j-1] == LIM) dp[i][j-1] = deque(i, j-1);
 
  long long a = v[i]*c + dp[i+1][j];
  long long b = v[j-1]*c + dp[i][j-1];
 
  dp[i][j] = c < 0 ? min(a, b) : max(a, b);
  return dp[i][j];
}
 
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
 
  std::cin >> N;
  v.resize(N);
  dp = vector<vector<long long>>(N+1, vector<long long>(N+1, LIM));
 
  for (int i = 0; i < N; ++i)
  {
    long long val;
    cin >> val;
    v[i] = val;
  }
 
  std::cout << deque(0, N); 
 
  return 0;
}