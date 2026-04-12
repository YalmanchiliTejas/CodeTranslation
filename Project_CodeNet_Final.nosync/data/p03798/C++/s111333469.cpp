#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 2e5 + 5; 
using namespace std;

int n, a[N], b[N];
char s[N]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

bool solve(int pos, int x, int y)
{
	b[pos] = x, b[pos + 1] = y, b[pos - 1] = b[pos] ^ a[pos] ^ b[pos + 1];
	for(int i = pos + 1; i < 2 * n; i++) b[i + 1] = b[i] ^ a[i] ^ b[i - 1]; 
	if(b[2 * n] == b[n] && b[2 * n] ^ a[2 * n] == b[2 * n - 1] ^ b[n + 1]) return 1; 
	return 0; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> (), scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) a[i] = a[i + n] = s[i] == 'o';
	if(solve(n + 1, 0, 0))
	{
		for(int i = n + 1; i <= 2 * n; i++) printf("%c", b[i] ? 'S' : 'W');
		puts(""); return 0; 
	}
	if(solve(n + 1, 0, 1))
	{
		for(int i = n + 1; i <= 2 * n; i++) printf("%c", b[i] ? 'S' : 'W');
		puts(""); return 0; 
	}
	if(solve(n + 1, 1, 0))
	{
		for(int i = n + 1; i <= 2 * n; i++) printf("%c", b[i] ? 'S' : 'W');
		puts(""); return 0; 	
	}
	if(solve(n + 1, 1, 1))
	{
		for(int i = n + 1; i <= 2 * n; i++) printf("%c", b[i] ? 'S' : 'W');
		puts(""); return 0; 
	}
	puts("-1"); 
	return 0; 
}
