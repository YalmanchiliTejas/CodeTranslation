#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int INF = 1e9 + 100;
const lli INF64 = (1LL << 61) + 100;
const lli MOD = 1000*1000*1000+7;
lli bpow(lli a, lli b) {
	if(b == 0) return 1;
	if(b == 1) return a % MOD;
	lli r = bpow(a, b >> 1);
	r = (r * r) % MOD;
	return (r * (((b&1)?a:1) % MOD)) % MOD;
}
lli multInverse(lli a) {
	return bpow(a, MOD - 2);
}
lli modMult(lli a, lli b) {
	return (a * b) % MOD;
}
lli modSub(lli a, lli b) {
	a += MOD;
	lli r = a - b;
	if(r >= MOD) return r - MOD;
	return r;
}
lli modAdd(lli a, lli b) {
	lli r = a + b;
	if(r >= MOD) return r - MOD;
	return r;
}
string NN;
string num;
int k, n;
lli k3() {
	lli ans = 0;
	for(int i = k-1; i < n-1; i++)
		ans += 9 * 9LL * 9 * ((i * (i-1)) / 2);
	for(char dig1 = '1'; dig1 <= '9'; dig1++) {
		num[0] = dig1;
		for(int ii = 1; ii < n; ii++) {
			for(char dig2 = '1'; dig2 <= '9'; dig2++) {
				num[ii] = dig2;
				for(int jj = ii+1; jj < n; jj++) {
					for(char dig3 = '1'; dig3 <= '9'; dig3++) {
						num[jj] = dig3;
						for(int cccc = 0; cccc < n; cccc++) {
							if(num[cccc] < NN[cccc]) ans++;
							if(num[cccc] != NN[cccc]) break;
						}
					}
					num[jj] = '0';
				}
			}
			num[ii] = '0';
		}
	}
	return ans;
}
lli k2() {
	lli ans = 0;
	for(int i = k; i < n; i++)
		ans += 9 * 9 *(i-1);
	for(int j = 1; j <= 9; j++) {
		num[0] = j + '0';
		for(int kk = 1; kk < n; kk++) {
			for(int ll = 1; ll <= 9; ll++) {
				num[kk] = ll + '0';
				for(int cccc = 0; cccc < n; cccc++) {
					if(num[cccc] < NN[cccc]) ans++;
					if(num[cccc] != NN[cccc]) break;
				}
			}
			num[kk] = '0';
		}
	}
	return ans;
}
lli k1() {
	lli ans = 0;
	for(int i = k; i < n; i++)
		ans += 9;
	for(int j = 1; j <= 9; j++) {
		num[0] = j + '0';
		for(int cccc = 0; cccc < n; cccc++) {
			if(num[cccc] < NN[cccc]) ans++;
			if(num[cccc] != NN[cccc]) break;
		}
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	cin >> NN;
	cin >> k;
	n = NN.length();
	num = "";
	for(int i = 1; i <= n; i++)
		num.push_back('0');
	
	lli anss;
	if(k == 1) anss = k1();
	if(k == 2) anss = k2();
	if(k == 3) anss = k3();
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(NN[i] != '0') 
			cnt++;
	//cout << anss << "\n";
	if(cnt == k) anss++;
	cout << anss << "\n";
	return 0;
}