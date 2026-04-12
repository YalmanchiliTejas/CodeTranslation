#include <bits/stdc++.h>

using namespace std;

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int main() {
	string s;
	cin >> s;
	int n = s.length(), k;
	cin >> k;
	int ans = C(n, k) * pow(9, k), digits = 0;
	for(int i = 0; i < n && k - digits; i++) {
		int d = s[i] - '0';
		ans -= (9 - d) * C(n - (i + 1), k - digits - 1) * pow(9, k - digits - 1);
		if(d != 0) digits++;
	}	
	printf("%d", ans);
}