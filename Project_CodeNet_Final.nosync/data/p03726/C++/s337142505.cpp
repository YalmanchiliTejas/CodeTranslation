#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int n;
vector<int> tr[100001];
bool good[100001], yes[100001];

void Y() { printf("First\n"), exit(0); }

void go(int v = 1, int p = 0){
	bool g = true;
	int y = 0;
	f(i, 0, tr[v].size()){
		int u = tr[v][i];
		if (u == p)continue;
		go(u, v);
		if (!good[u])g = false;
		if (yes[u])++y;
	}
	if (y > 1)Y();
	if (y == 1)good[v] = true;
	if (g)yes[v] = true;
}

int main(){
	scanf("%d", &n);
	f(i, 1, n){
		int a, b;
		scanf("%d%d", &a, &b);
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	go();
	if (yes[1])Y();
	printf("Second\n");
}