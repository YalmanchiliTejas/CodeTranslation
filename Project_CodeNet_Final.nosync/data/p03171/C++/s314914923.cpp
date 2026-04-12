#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N;
  std::cin >> N;
  std::vector<ll> A(N);
  for(int i=0;i<N;i++) scanf("%lld", &A[i]);
  ll dp[N][N][2];
  for(int i=0;i<N;i++) dp[i][i][0] = A[i], dp[i][i][1] = -A[i];
  for(int w=1;w<N;w++){
    for(int i=0;i+w<N;i++){
      dp[i][i+w][0] = max(dp[i+1][i+w][1]+A[i], dp[i][i+w-1][1]+A[i+w]);
      dp[i][i+w][1] = min(dp[i+1][i+w][0]-A[i], dp[i][i+w-1][0]-A[i+w]);
    }
  }
  std::cout << dp[0][N-1][0] << '\n';
  return 0;
}
