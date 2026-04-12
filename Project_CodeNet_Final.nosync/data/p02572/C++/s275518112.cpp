#include <bits/stdc++.h>

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x) {
	static char buf[45], *tail = buf; 
	if (!x) {
		putchar('0'); 
	} else {
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

using namespace std; 

const int MaxN = 2e5 + 5; 
const int mod = 1e9 + 7; 

int n; 
int a[MaxN]; 

int main() {
	read(n); 

	int sum = 0, sum2 = 0; 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
		sum = (sum + a[i]) % mod; 
		sum2 = (sum2 + 1LL * a[i] * a[i]) % mod; 
	}

	cout << (1LL * sum * sum + mod - sum2) % mod * (mod + 1 >> 1) % mod << '\n'; 

	return 0; 
}