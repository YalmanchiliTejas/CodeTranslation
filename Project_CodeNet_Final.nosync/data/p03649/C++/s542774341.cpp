#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N, 0);
	for (int i = 0;i < N;i++)
		cin >> A[i];
	//まず全てがN-1以下になるまで何回必要かを考える
	//一つだけN減って他全て1増えるなら
	//N+1減って水準となるnが1下がったことにすればよい
	ll cnt = 1, ans = 0;
	while (cnt) {
		cnt = 0;
		for (int i = 0;i < N;i++) {
			B[i] = A[i] / N;//回かかる
			A[i] %= N;
			cnt += B[i];
		}
		for (int i = 0;i < N;i++) {
			A[i] += (cnt - B[i]);
			B[i] = 0;
		}
		ans += cnt;
	}
	cout << ans << endl;
}