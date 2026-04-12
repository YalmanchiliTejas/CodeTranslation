#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<'\n'

namespace T {
	int l[23333333], r[23333333];
	int size[23333333];
	long long v[23333333];
	int root=0, tot=0;
	int merge(int x, int y) {
		if (!x || !y) {
			return x+y;
		}
		if (v[x]<v[y]) {
			swap(x, y);
		}
		r[x]=merge(r[x], y);
		size[x]+=size[y];
		if (size[l[x]]<size[r[x]]) {
			swap(l[x], r[x]);
		}
		return x;
	}
	inline long long top(void) {
		if (!root) {
			return -0x3f3f3f3f;
		} else {
			return v[root];
		}
	}
	inline void pop(void) {
		root=merge(l[root], r[root]);
	}
	inline void insert(long long x) {
		++tot;
		l[tot]=r[tot]=0;
		size[tot]=1;
		v[tot]=x;
		root=merge(root, tot);
	}
}

long long a[66];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%lld", a+i);
		T::insert(a[i]);
	}
	long long k=0;
	while (T::top()+k>=n) {
		long long p=T::top()+k;
	//	debug(p);
		T::pop();
		k+=p/n;
	//	debug(k);
		p%=n;
	//	debug(p);
		T::insert(p-k);
	}
	cout<<k;
	return 0;
}