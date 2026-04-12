#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int N;
int x[100010], y[100010];
int idx1[100010], idx2[100010];
//vector<vector<int> > G(100010);
//vector<vector<int> > G2(100010);
int fa[100010];
int E1[500010], E2[500010], L[500010];
int m;
int idx[500010];
long long res;

int cmp1(const void *aa, const void *bb)
{
	int i1 = *((int *)aa);
	int i2 = *((int *)bb);
	if(x[i1] > x[i2])
		return 1;
	else if(x[i1] < x[i2])
		return -1;
	else{
		return y[i1]-y[i2];
	}
}

int cmp2(const void *aa, const void *bb)
{
	int i1 = *((int *)aa);
	int i2 = *((int *)bb);
	if(y[i1] > y[i2])
		return 1;
	else if(y[i1] < y[i2])
		return -1;
	else{
		return x[i1]-x[i2];
	}
}

int cmp(const void *aa, const void *bb)
{
	int i1 = *((int *)aa);
	int i2 = *((int *)bb);
	return L[i1] - L[i2];
}

int getFa(int u)
{
	int uu = u;
	while(fa[u] != -1)
		u = fa[u];
	while(fa[uu] != -1){
		int tu = fa[uu];
		fa[uu] = u;
		uu = tu;
	}
	return u;
}

void solve()
{
	int i;
	m = 0;
	for(i=0; i<N; i++){
		idx1[i] = i;
	}
	qsort(idx1, N, sizeof(int), cmp1);
	for(i=0; i<N-1; i++){
		//G[idx1[i]].push_back(idx1[i+1]);
		//G[idx1[i+1]].push_back(idx1[i]);
		//G2[idx1[i]].push_back(abs(x[idx1[i+1]]-x[idx1[i]]));
		//G2[idx1[i+1]].push_back(abs(x[idx1[i+1]]-x[idx1[i]]));
		E1[m] = idx1[i];
		E2[m] = idx1[i+1];
		L[m] = abs(x[idx1[i+1]]-x[idx1[i]]);
		m ++;
	}
	for(i=0; i<N; i++){
		idx2[i] = i;
	}
	qsort(idx2, N, sizeof(int), cmp2);
	for(i=0; i<N-1; i++){
		//G[idx2[i]].push_back(idx2[i+1]);
		//G[idx2[i+1]].push_back(idx2[i]);
		//G2[idx2[i]].push_back(abs(y[idx2[i+1]]-y[idx2[i]]));
		//G2[idx2[i+1]].push_back(abs(y[idx2[i+1]]-y[idx2[i]]));
		E1[m] = idx2[i];
		E2[m] = idx2[i+1];
		L[m] = abs(y[idx2[i+1]]-y[idx2[i]]);
		m ++;
	}
	for(i=0; i<N; i++)
		fa[i] = -1;
	for(i=0; i<m; i++){
		idx[i] = i;
	}
	qsort(idx, m, sizeof(int), cmp);
	res = 0;
	for(i=0; i<m; i++){
		int u = E1[idx[i]], v = E2[idx[i]], len = L[idx[i]];
		int f1 = getFa(u);
		int f2 = getFa(v);
		if(f1 == f2)
			continue;
		else{
			fa[f1] = f2;
			res += len;
		}
	}
	printf("%lld\n", res);
}

int main()
{
	int i;
	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%d%d", &x[i], &y[i]);
	solve();
	return 0;
}