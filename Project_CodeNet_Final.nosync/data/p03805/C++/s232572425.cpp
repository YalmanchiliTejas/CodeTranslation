#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for (int i=s;i<e;i++)
#define FOE(i,s,e) for (int i=s;i<=e;i++)
#define FOD(i,s,e) for (int i=s;i>=e;i--)
#define SET(a,e) memset(a,e,sizeof(a))
#define LL long long
#define LD long double
#define pb push_back
#define x first
#define y second
#define PII pair<int,int>
#define PLI pair<LL,int>
#define PIL pair<int,LL>
#define PLL pair<LL,LL>
#define PDD pair<LD,LD>
#define eps 1e-9
#define HH1 402653189
#define HH2 1610612741

int n, m, ans, x, y, a[10];
bool edge[10][10];

int main () {
	
	scanf("%d%d", &n, &m);
	
	FOR(i, 0, m) {
		scanf("%d%d", &x, &y);
		edge[x][y] = edge[y][x] = 1;
	}
	
	FOR(i, 0, n) a[i] = i + 1;
	
	do {
		bool ok = 1;
		FOR(i, 1, n) if (edge[a[i]][a[i - 1]] == 0) ok = 0;
		if (ok) ans++;
	} while (next_permutation(a + 1, a + n));
	
	printf("%d\n", ans);
	
	return 0;
	
}