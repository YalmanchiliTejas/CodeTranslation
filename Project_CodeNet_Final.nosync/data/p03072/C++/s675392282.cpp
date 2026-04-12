#include<bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;

int n;
int h[maxn];
int hst, ans;

void inline Init()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", h + i);
}

void inline Solve()
{
	for(int i = 1; i <= n; ++i) {
		if(h[i] >= hst) {
			++ans;
			hst = h[i];
		}
	}
	printf("%d\n", ans);
}

int main()
{
	Init();
	Solve();
	return 0;
}