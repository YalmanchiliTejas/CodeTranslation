#include<iostream>
using namespace std;

const int N_MAX = 3000;
typedef unsigned long long ull;
ull c[N_MAX+1][N_MAX+1];
ull s[N_MAX+1][N_MAX+1];

unsigned int power2(unsigned int n, unsigned int m) {
	ull r = 1;
	ull t = 2;
	while(n > 0) {
		if(n & 1) r = (r * t) % m;
		t = (t * t) % m;
		n >>= 1;
	}
	return (unsigned int)r;
}

int main() {
	unsigned int n, m;
	cin >> n >> m;
	for(int i=0;i<=n;i++) c[i][0] = c[i][i] = 1;
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) {
		c[i][j] = (c[i-1][j-1] + c[i-1][j]) % m;
	}
	for(int i=0;i<=n;i++) s[i][0] = 1;
	for(int i=1;i<=n;i++) s[0][i] = 0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		s[i][j] = ((j+1) * s[i-1][j] + s[i-1][j-1]) % m;
	}
	ull ans = 0;
	for(int i=0;i<=n;i++) {
		ull tmp = 0;
		for(int j=0;j<=i;j++) tmp = (tmp + s[i][j] * power2((n-i)*j, m)) % m;
		tmp = (tmp * power2(power2(n-i, m-1), m)) % m;
		tmp = (tmp * c[n][i]) % m;
		if(i % 2 == 1) tmp = m - tmp;
		ans = (ans + tmp) % m;
	}
	cout << ans << endl;
	return 0;
}
