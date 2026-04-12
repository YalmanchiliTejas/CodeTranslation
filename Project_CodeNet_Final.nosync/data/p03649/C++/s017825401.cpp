#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<'\n'

namespace T {
	int l[50000], r[50000];
	int size[50000];
	long long v[50000];
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
//	debug(T::tot);
	cout<<k;
	return 0;
}
/*
50
10000000000000008
10000000000000000
10000000000000233
10000000000000666
10000000000000777
10000000000000888
10000000000000999
10000000000000345
10000000000000000
10000000234000004
10000000003240001
10000000002300003
10000000000000567
10000000000000977
10000000000000891
10000000000012345
10000000000023456
10000000000034567
10000000000045678
10000000000056789
10000000000067891
10000000000078912
10000000000087654
10000000000098765
10000000000019876
10000000000000008
10000000000000000
10000000000000233
10000000000000666
10000000000000777
10000000000000888
10000000000000999
10000000000000345
10000000000000000
10000000234000004
10000000003240001
10000000002300003
10000000000000567
10000000000000977
10000000000000891
10000000000012345
10000000000023456
10000000000034567
10000000000045678
10000000000056789
10000000000067891
10000000000078912
10000000000087654
10000000000098765
10000000000019876

*/