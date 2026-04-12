#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	ll d = 1e+9 + 7;
	int N;
	cin >> N;
	ll A[N];
	ll tot = 0;
	rep(i,N) {
		cin >> A[i];
		tot += A[i];
		tot = tot%d;
	}
	tot = (tot - A[0] + d)%d;
	ll ans = tot*A[0];
	ans %= d;
	for (int i = 1; i < N-1; i++){
		tot = (tot - A[i] + d)%d;
		ans += tot*A[i];
		ans %= d;
	}
	ans = (ans+d)%d;
	cout << ans << endl;
return 0;
}
