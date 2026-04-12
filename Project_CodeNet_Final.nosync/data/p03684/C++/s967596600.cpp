#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int p[100005], id[100005];
int x[100005], y[100005];

int find(int at) {
	if (p[at] == at) return at;
	return p[at] = find(p[at]);
}

int cmpx(int a, int b) {
	return x[a] < x[b];
}

int cmpy(int a, int b) {
	return y[a] < y[b];
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		scanf("%d %d", &x[i], &y[i]);
		id[i] = i;
	}
	sort(id, id + n, cmpx);
	vector<tuple<LL, int, int>> V;
	for (int i = 0; i < n - 1; i++) {
		V.push_back(make_tuple(x[id[i + 1]] - x[id[i]], id[i], id[i + 1]));
	}
	sort(id, id + n, cmpy);
	for (int i = 0; i < n - 1; i++) {
		V.push_back(make_tuple(y[id[i + 1]] - y[id[i]], id[i], id[i + 1]));
	}
	sort(ALL(V));
	LL cost = 0;
	for (tuple<LL, int, int>& q : V) {
		int a = std::get<1>(q);
		int b = std::get<2>(q);
		if (find(a) == find(b)) continue;
		cost += MIN(ABS(x[a] - x[b]), ABS(y[a] - y[b]));
		p[find(a)] = find(b);
	}
	printf("%lld\n", cost);
	return 0;
}
