#include <bits/stdc++.h>

#pragma GCC optimize(2)

#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

int gi() {
	int f = 1, x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return f * x;
}

int main() {
	int a = gi(), b = gi();
	puts(a == b ? "Yes" : "No");

  return 0;
}
