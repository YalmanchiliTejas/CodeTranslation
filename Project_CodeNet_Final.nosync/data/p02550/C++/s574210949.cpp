#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	ll N, X, M;
	cin >> N >> X >> M;

	vector<ll> A(M,-1); // 回数
	vector<ll> B(M,-1); // Cumm
	ll c = 0;
	int f = 0;
	for(ll i = 1; i <= N; i++){
		c = c + X;
		if(A[X] == -1 || f == 1){ // まだ来てない
			A[X] = i;
			B[X] = c;
		}else{
			ll j = A[X]; // 周期 = i - j
			ll d = c - B[X];
			ll r = (N - i) / (i - j); // 周回数
			c += r * d;
			i = i + r * (i - j); // 周期回数
			f = 1;
		}
		X = (X * X) % M;
	}

	cout << c << endl;
	return(0);
}
