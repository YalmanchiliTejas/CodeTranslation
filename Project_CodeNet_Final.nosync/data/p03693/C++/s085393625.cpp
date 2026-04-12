#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long LL;
inline int read()
{
	int l = 0, f = 1;
	char a = getchar();
	for (; a < '0' || a > '9'; a = getchar())
		if (a == '-') f = -1;
	for (; a >= '0' && a <= '9'; a = getchar())
		l = l * 10+a-48;
	return l * f;
}
char ss;
int x = 0;
int main()
{
	scanf("%c", &ss);
	while(ss < '0' || ss > '9') scanf("%c", &ss);
	x = x*10+ss-48;
	scanf("%c", &ss);
	while(ss < '0' || ss > '9') scanf("%c", &ss);
	x = x*10+ss-48;
	scanf("%c", &ss);
	while(ss < '0' || ss > '9') scanf("%c", &ss);
	x = x*10+ss-48;
	if (x%4 == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}