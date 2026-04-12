#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i,a,b) for(int i=int(a),nn=int(b);i<=nn; ++i)
#define vep(i,a,b) for(int i=int(a),nn=int(b);i>=nn; --i)
#define xep(i,b) for(int i=0,nn=int(b);i<nn; ++i)

#define pb push_back
#define sz(x) (int)(x.size())

const int N = 100100;

vector<int> v[N];
int n;

inline void in(int &x) {
	char c = getchar(); int f=1;
	for (; c<'0'||c>'9'; c=getchar()) f=(c=='-'?-1:f);
	for (x=0; c>='0'&&c<='9'; c=getchar()) x=x*10+c-48;
	x *= f;
}

int as = 1;
bool vs[N];

void dfs(int x, int fa = 0) {
	int y;
	xep(i, sz(v[x]))
		if (y=v[x][i], y!=fa)
			dfs(y, x);
	if (!vs[x]) {
		if (!fa || vs[fa]) as = 0;
		else vs[x] = vs[fa] = 1;
	}
}

int main() {
	in(n);
	int x, y;
	rep(i, 1, n-1) {
		in(x), in(y);
		v[x].pb(y), v[y].pb(x);
	}

	dfs(1);
	puts((as ? "Second" : "First"));

	return 0;
}
