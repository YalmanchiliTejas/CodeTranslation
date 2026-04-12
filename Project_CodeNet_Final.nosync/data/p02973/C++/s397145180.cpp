#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>

typedef long long ll;

using namespace std;

ll INF = (ll)1 << 62;
ll getLIS(vector<ll> a, ll N)
{
	vector<ll> dp(N, INF);
	for (ll i = 0; i < N; ++i) {
		*upper_bound(dp.begin(), dp.begin() + N, a[i]) = a[i];
	}
	return lower_bound(dp.begin(), dp.begin() + N, INF) - dp.begin();
}

int main(int argc, const char * argv[]) {
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll i;
  for(i=N-1;i>=0;i--){
    cin >> A[i];
  }
  cout << getLIS(A,N);

  return 0;
}
