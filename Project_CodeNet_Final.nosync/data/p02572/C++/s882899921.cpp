#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];

  ll sum = 0, triSum = 0;
  rep(i,N) {
    sum += A[i];
    sum %= MOD;
    triSum += sum * A[i];
    triSum %= MOD;
  }
  sum *= sum;
  sum %= MOD;
  ll ans = sum + MOD - triSum;
  ans %= MOD;
  cout << ans << endl;

  return 0;
}