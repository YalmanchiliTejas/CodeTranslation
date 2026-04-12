#include <bits/stdc++.h>
#define itn int
#define gI gi
 
using namespace std;
 
typedef long long ll;
 
inline int gi()
{
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}
 
inline ll gl()
{
	ll f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}
 
int n, m, a[100003];
char s[100003];
 
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = gi(), m = gi();
	if (n == m) puts("Yes");
	else puts("No");
	return 0;
}