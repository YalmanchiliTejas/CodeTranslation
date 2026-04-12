#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct node{
	int id, val;
};

struct edge{
	int x,y,val;
};

// node の　val の　昇順
int cmp(node a,node b){ return a.val < b.val;}

// edge の　val の　昇順
int cmp2(edge a,edge b){ return a.val < b.val;}

int f[100000];

int find(int x){
	if(f[x]!=x) f[x] = find(f[x]);
	return f[x];
}

// 最小全域木をクラスカル法で求める
// 対象の辺はx座標でソートして隣接する頂点間の辺、
//         y座標でソートして隣接する頂点間の辺だけでよい

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	node a[n],b[n];
	edge c[2*n-2];

	rep(i,n){
		int x,y;
		cin >> x >> y;
		a[i].id = i;
		a[i].val = x;
		b[i].id = i;
		b[i].val = y;
	}
	
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	rep(i,n) f[i] = i;

	ll ans = 0;
	rep(i,n-1){
		c[i].x = a[i].id;
		c[i].y = a[i+1].id;
		c[i].val = abs(a[i+1].val - a[i].val);
	}
	rep(i,n-1){
		c[i+n-1].x = b[i].id;
		c[i+n-1].y = b[i+1].id;
		c[i+n-1].val = abs(b[i+1].val - b[i].val);
	}

	sort(c,c+2*n-2,cmp2);

	rep(i,2*n-2){
		int x = find(c[i].x);
		int y = find(c[i].y);
		if(x!=y){
			ans += c[i].val;
			f[x] = y;
		}
	}

	cout << ans << endl;
}