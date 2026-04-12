#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void readin(T &x) {
	x = 0;
	T fh = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= fh;
}
inline void d_read(double &x) {
	x = 0.0;
	int fh = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
	if (ch == '.') {
		double num = 1.0;
		ch = getchar();
		for (; isdigit(ch); ch = getchar()) x = x + (num /= 10) * (ch ^ 48);
	}
	x *= fh;
}

template <typename T>
inline void wt(T x) {
	if (x > 9) wt(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x, char c) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	wt(x);
	putchar(c);
}

int main() {
	int n;
	cin >> n;
	if (n >= 30) {
		puts("Yes");
	}
	else puts("No");
	return 0;
}


