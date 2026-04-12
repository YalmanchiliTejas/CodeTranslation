#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int r, g, b;

int main() {
	scanf("%d%d%d", &r, &g, &b);
	int tot = r * 100 + g * 10 + b;
	puts(tot % 4 == 0 ? "YES" : "NO");
	return 0;
}