#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int d[300000];
int a[300000];

#ifndef MAX
#define MAX 1200000
#endif

//Range Update Query+Range Sum Query
template<class T>
class RUQ_RSQ {
public:
	int n;
	T dat[MAX], lazy[MAX], ZERO, DEFAULT;
	void init(int n_, T d = INT_MAX, T t = 0) {
		DEFAULT = d;
		ZERO = T();
		n = 1; while (n < n_)n <<= 1;
		for (int i = 0; i < 2 * n - 1; i++) {
			dat[i] = t; lazy[i] = DEFAULT;
		}
	}
	inline void push(int k, int s) {
		if (lazy[k] == DEFAULT)return;
		dat[k] = lazy[k] * s;
		if (k < n - 1) {
			lazy[k * 2 + 1] = lazy[k];
			lazy[k * 2 + 2] = lazy[k];
		}
		lazy[k] = DEFAULT;
	}
	inline void update_node(int k) {
		dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
	}
	inline void update(int a, int b, T x, int k, int l, int r) {
		push(k, r - l);
		if (r <= a || b <= l)return;
		if (a <= l&&r <= b) {
			lazy[k] = x; push(k, r - l); return;
		}
		update(a, b, x, k * 2 + 1, l, (l + r) / 2);
		update(a, b, x, k * 2 + 2, (l + r) / 2, r);
		update_node(k);
	}
	inline T query(int a, int b, int k, int l, int r) {
		push(k, r - l);
		if (r <= a || b <= l)return ZERO;
		if (a <= l&&r <= b)return dat[k];
		T lb = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T rb = query(a, b, k * 2 + 2, (l + r) / 2, r);
		update_node(k);
		return lb + rb;
	}
	inline void update(int a, int b, T x) {
		update(a, b, x, 0, 0, n);
	}
	inline void update(int a, T x) {
		update(a, a + 1, x);
	}
	inline T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
	inline T query(int a) {
		return query(a, a + 1);
	}
};

RUQ_RSQ<int> seg1,seg2;
int main(){
	int n;scanf("%d",&n);
	rep(i,n){
		scanf("%d",&d[i]);
		a[i]=i*10;
	}
	seg1.init(n);seg1.update(0,1);
	seg2.init(n);seg2.update(n-1,1);
	rep(i,n){
		if(!seg1.query(i))continue;
		int k=upper_bound(a,a+n,a[i]+d[i])-a;
		seg1.update(i+1,k,1);
	}
	if(seg1.query(n-1)==0){
		puts("no");return 0;
	}
	for(int i=n-1;i>=0;i--){
		if(!seg2.query(i))continue;
		int k=lower_bound(a,a+n,a[i]-d[i])-a;
		seg2.update(k,i,1);	
	}
	if(seg2.query(0)==0){
		puts("no");
		return 0;
	}
	puts("yes");
}