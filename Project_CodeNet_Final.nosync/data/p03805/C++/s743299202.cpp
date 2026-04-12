#include <bits/stdc++.h>
using namespace std;

#define mp(x, y) make_pair((x), (y))

typedef long long ll;

int n, m;
int e[42][42];
int ans;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		e[u][v]=1;
		e[v][u]=1;
	}
	vector<int> perm;
	for(int i=0; i<n; i++) {
		perm.push_back(i);
	}
	do {
		if(perm[0]!=0) continue;
		int ok=1;
		for(int i=1; i<n; i++) {
			if(!e[perm[i-1]][perm[i]]) ok=0;
		}
		ans+=ok;
	} while(next_permutation(perm.begin(), perm.end()));
	printf("%d\n", ans);

	return 0;
}