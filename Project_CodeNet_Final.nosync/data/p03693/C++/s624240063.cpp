#include <bits/stdc++.h>

using namespace std;

int main() {
	int r, g, b;
	scanf( "%d%d%d", &r, &g, &b );
	int x = r*100 + g*10 + b;
	puts( x % 4 == 0 ? "YES" : "NO" );
	return 0;
}
