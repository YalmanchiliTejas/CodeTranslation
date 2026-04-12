#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf((100*r + 10*g + b) % 4 == 0 ? "YES\n" : "NO\n");
}
