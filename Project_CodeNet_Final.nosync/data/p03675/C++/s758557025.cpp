#include<bits/stdc++.h>
using namespace std;
#define R register int
#define AC 201000

int n, l, r;
int s[AC], ans[AC];

inline int read()
{
	int x = 0;char c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

void pre()
{
	n = read(), l = 1, r = n;
	for(R i = 1; i <= n; i ++) s[i] = read();
}

void work()
{
	int now = 0;
	for(R i = n; i; i --)
	{
		if(!now) ans[l ++] = s[i];
		else ans[r --] = s[i];
		now ^= 1;
	}
	for(R i = 1; i <= n; i ++) printf("%d ", ans[i]);
}

int main()
{
	//freopen("in.in", "r", stdin);
	pre();
	work();
	//fclose(stdin);
	return 0;
}