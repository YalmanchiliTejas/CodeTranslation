#include <bits/stdc++.h>
using namespace std;

#define mp(x, y) make_pair((x), (y))

typedef long long ll;

int n;
set<int> nex[100005];
int d[100005];
int l[100005];
int beg, End;
int m[100005];

int main()
{
	scanf("%d", &n);
	if(n%2==1) {
		printf("First\n");
		return 0;
	}
	for(int i=0; i<n-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		nex[u].insert(v);
		nex[v].insert(u);
		d[u]++;
		d[v]++;
	}
	for(int i=0; i<n; i++) {
		if(d[i]==1) {
			l[End++]=i;
		}
	}
	while(beg<End) {
		int cur=l[beg++];
		if(m[cur]) continue;
		m[cur]=1;
		int nei=*nex[cur].begin();
		if(m[nei]) {
			printf("First\n");
			return 0;
		} else {
			m[nei]=1;
			for(set<int>::iterator it=nex[nei].begin(); it!=nex[nei].end(); it++) {
				nex[*it].erase(nei);
				if(nex[*it].size()==1) {
					l[End++]=*it;
				}
			}
		}
	}
	printf("Second\n");

	return 0;
}