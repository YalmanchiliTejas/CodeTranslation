#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll a[55], p[55];
ll f(ll N, ll X) {
	if (N == 0) {
		if(X>0) return 1;
		else return 0;
	}
	else if (X <= a[N - 1] + 1) return f(N - 1, X - 1);
	else return p[N - 1] + 1 + f(N - 1, X - a[N - 1] - 2);
}
int main() {
	ll N, X;
	cin >> N >> X;
	a[0] = 1;
	p[0] = 1;
	for (int i = 0; i < N; i++) a[i + 1] = 2 * a[i] + 3;
	for (int i = 0; i < N; i++) p[i + 1] = 2 * p[i] + 1;
	cout << f(N,X) << endl;
}