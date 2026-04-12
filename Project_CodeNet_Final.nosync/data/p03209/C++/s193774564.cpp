#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll pow(ll a, ll n) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a) {
		if (n % 2LL == 1LL) {
			ret = ret * a;
		}
	}
	return ret;
}

ll f(ll n, ll x){
  if(x>=pow(2LL,n+2LL)-3) return pow(2LL,n+1LL)-1;
  if(x<=0LL) return 0LL;
  if(n==0LL&&x==1LL) return 1LL;
  if(x<=pow(2LL,n+1LL)-2LL) return f(n-1,x-1);
  if(x>pow(2LL,n+1LL)-2LL) return f(n-1,x-1)+1+f(n-1,x-pow(2LL,n+1LL)+1);
}

int main() {
  ll N, X;
  cin >> N >> X;
  cout<<f(N,X)<<endl;
}