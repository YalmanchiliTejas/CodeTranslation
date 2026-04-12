#include<bits/stdc++.h>
using namespace std;

int n;
long long psum[3003], f[3003];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> psum[i], f[i] = psum[i], psum[i] += psum[i - 1];
	for(int i = 2; i <= n; ++i) {
		int ed = n - i + 1;
		for(int j = 1; j <= ed; ++j)
			f[j] = psum[j + i - 1] - psum[j - 1] - min(f[j], f[j + 1]);
	}
	cout << f[1] * 2 - psum[n] << endl;
	return 0;
}