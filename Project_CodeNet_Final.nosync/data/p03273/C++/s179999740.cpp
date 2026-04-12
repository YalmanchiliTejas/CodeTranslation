#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <ctime> 
using namespace std;

#define pb push_back
#define All(a) a.begin(), a.end()
#define met(a, b) memset(a, b, sizeof(a))
#define rep1(i, l, r) for(int i = l; i <= r; ++i)
#define rep2(i, l, r) for(int i = l; i < r; ++i) 
#define per(i, r, l) for(int i = r; i >= l; --i)
typedef long long ll;
typedef double db;
typedef long double ldb;
const int NIL = -1;
const int oo = 0x3f3f3f3f;
const ll INF = 2e18;
const db eps = 1e-8;
const db PI = acos(-1.0);
const int maxn = 200;

char G[maxn][maxn];
int col[maxn], row[maxn];

inline int read(void)
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{ if(ch == '-') f = -1; ch = getchar(); } 
	while(ch >= '0' && ch <= '9') {	x = (x << 1) + (x << 3) + ch - '0';	ch = getchar();	}
	return x * f;
}

inline void write(int x)
{
	if(x < 0) { putchar('-'); x = -x; }
    if(x >= 10) write(x/10); 
	putchar(x%10+'0'); 
}

int main(void)
{
	int n = read(), m = read();
	rep1(i, 1, n)
	{
		rep1(j, 1, m)
		{
			cin>>G[i][j];
			if(G[i][j] == '#')
			{	
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	rep1(i, 1, n)
	{
		if(!row[i]) continue;
		rep1(j, 1, m)
		{
			if(!col[j]) continue;
			printf("%c", G[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 