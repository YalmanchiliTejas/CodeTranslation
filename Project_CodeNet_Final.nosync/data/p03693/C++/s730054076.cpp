#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int main(){
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	int x = r * 100 + g * 10 + b;
	printf("%s\n", x % 4 ? "NO" : "YES");
}