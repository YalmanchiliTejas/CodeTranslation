#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0, fh = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            fh = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * fh;
}
int a, b, c, x, y;
LL ans;
int main() {
	a = read(); b = read(); c = read(); x = read(); y = read();
	if (x < y) { swap(x, y); swap(a, b); }
	if (c * 2 < a + b) ans += y * c * 2;
	else ans += a * y + b * y;
	x -= y;
	if (a < c * 2) ans += x * a;
	else ans += x * c * 2;
	cout << ans;
	return 0;
}