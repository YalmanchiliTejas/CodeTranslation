#include <cstdio> 
#define SZ 3009 
#define llg long long 
using namespace std; 

int n; 
llg p, S[SZ][SZ], ans = 0, C[SZ][SZ]; 

int read(); 
llg fsq(llg x, llg kn, llg mod = p) {
	llg ret = 1; 
	while (kn) {
		if (kn & 1) (ret *= x) %= mod; 
		(x *= x) %= mod; kn >>= 1; 
	} 
	return ret; 
} 
void get_S() {
	for (int i = 0; i <= n + 1; ++i) C[i][0] = 1; S[0][0] = 1; 
	for (int i = 1; i <= n + 1; ++i) for (int j = 1; j <= i; ++j) 
		S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j % p) % p; 
	for (int i = 1; i <= n + 1; ++i) for (int j = 1; j <= i; ++j) 
		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p; 
} 

int main() {
	n = read(), p = read(); S[0][0] = 1; get_S(); 
	for (int i = 0; i <= n; ++i) {
		llg now = 0, mult = 1, eac = fsq(2, n - i); 
		for (int j = 0; j <= i; ++j) {
			(now += mult * S[i + 1][j + 1] % p) %= p; 
			(mult *= eac) %= p; 
		} 
		(now *= fsq(2, fsq(2, n - i, p - 1))) %= p; 
		if (i & 1) (now *= (p - 1)) %= p; 
		(now *= C[n][i]) %= p; 
		(ans += now) %= p; 
	} 
	printf("%lld\n", ans); 
	return 0; 
} 

int read() {
	int x = 0, f = 1; char c = getchar(); 
	while (c > '9' || c < '0') f = (c == '-') ? -1 : f, c = getchar(); 
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar(); 
	return x * f; 
} 