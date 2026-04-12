#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;
const ll rmod[2] = {2147483647,2147483629};
const ll B[2] = {2147483624, 2147483627};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow(ll a, ll n, ll m) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a % m) {
		if (n % 2LL == 1LL) {
			ret = ret * a % m;
		}
	}
	return ret;
}

int main() {
  ll N,M,K;
  cin>>N>>M>>K;
  ll ans = (M*(M-1)*(M+1)/6%mod*N%mod*N + N*(N-1)*(N+1)/6%mod*M%mod*M)%mod;
  ll c = 1;
  rep(i,K-2){
    c = (c * (N*M-i-2))%mod;
    c = (c*pow((ll)i+1,mod-2,mod))%mod;
  }
  ans = (ans*c)%mod;
  cout<<ans<<endl;
}