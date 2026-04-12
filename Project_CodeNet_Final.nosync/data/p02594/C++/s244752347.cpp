#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

#define ll long long
#define rr register

#define inf 1e9
#define MAXN 100010

using namespace std;

inline int read() {
	int s = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

void print(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

int x;

signed main() {
	x = read();
	if (x >= 30) cout << "Yes";
	else cout << "No";
}