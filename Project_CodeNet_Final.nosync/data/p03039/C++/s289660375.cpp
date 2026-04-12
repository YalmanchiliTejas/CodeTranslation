#include <bits/stdc++.h>
using namespace std;

void MOD(vector<bool> &mod) {
	int n = 1000000005;
	for (int i = 0;i < 30;i++) {
		if (n % 2==1)
			mod[i] = true;
		else
			mod[i] = false;
		n /= 2;
	}
}

long long rev(long long n,vector<bool> mod) {
	//~10e9+5
	vector <long long> da(30,n);
	long long ans=1;
	if (mod[0])
		ans = n;
	for (int i = 1;i < 30;i++) {
		da[i] = (long long)(da[i - 1] * da[i - 1]) % 1000000007;
		if (mod[i])
			ans = (ans * da[i]) % 1000000007;
	}
	return ans;
}

long long kaijo(long long n) {
	long long ans = 1;
	for (int i = 1;i < n + 1;i++)
		ans = (ans*i) % 1000000007;
	return ans;
}

long long COMB(long long n, long long k,vector<bool> mod) {
	long long ans = (rev(kaijo(k),mod)*rev(kaijo(n - k),mod)) % 1000000007;
	return (kaijo(n)*ans) % 1000000007;
}

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	vector<bool> mod(30);
	MOD(mod);
	long long ans = 0;
	//n*m-2Ck-2*m*m*(n-i)
	long long pat = (m*m) % 1000000007;
	long long comb = COMB(n*m - 2, k - 2,mod);
	//cout << comb << endl;
	for (int i = 1;i < n;i++) {
		long long x = ((n - i)*pat) % 1000000007;
		x = (x*comb) % 1000000007;
		x = (x*i) % 1000000007;
		//cout << x << endl;
		ans = (ans + x) % 1000000007;
		//cout << ans << endl;
		if (ans < 0) {
			cout << i << endl;
			return 0;
		}
	}
	//cout << ans << endl;
	pat = (n*n) % 1000000007;
	for (int i = 1;i < m;i++) {
		long long x = ((m - i)*pat) % 1000000007;
		x = (x*comb) % 1000000007;
		x = (x*i) % 1000000007;
		ans = (ans + x) % 1000000007;
	}
	cout << ans << endl;
}