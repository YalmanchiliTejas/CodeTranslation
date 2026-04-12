#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	ll s=0,N,K;
	cin >> N >> K;

	if(K == 0)
		s = N*N;
	else
		rep(i,N-K) {
			ll x = i+1+K;
			s += N/x*(x-K)+max(0ll,N%x-K+1);
		}

	cout << s << endl;
}