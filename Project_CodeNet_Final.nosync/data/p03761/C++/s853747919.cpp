#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
const int N = 1e5 + 5; 
using namespace std; 

int n, cnt[N], mn[N];
char s[N]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin);
#endif
	n = read <int> ();
	for(int i = 0; i < 26; i++) mn[i] = 0x3f3f3f3f;
	for(int len, i = 1; i <= n; i++)
	{
		for(int j = 0; j < 26; j++) cnt[j] = 0; 
		scanf("%s", s + 1), len = strlen(s + 1); 
		for(int j = 1; j <= len; j++) cnt[s[j] - 'a']++; 
		for(int j = 0; j < 26; j++) mn[j] = min(mn[j], cnt[j]); 
	}
	for(int j = 0; j < 26; j++) mn[26] += mn[j];
	if(!mn[26]) { puts(""); return 0; }
	for(int j = 0; j < 26; j++)
		for(int i = 1; i <= mn[j]; i++) printf("%c", 'a' + j);
	puts(""); 
	return 0; 
}
