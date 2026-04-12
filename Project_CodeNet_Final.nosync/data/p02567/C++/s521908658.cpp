#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#include <atcoder/all>
#define popcount __builtin_popcount
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> P;
template<typename Monoid>
struct SegmentTree{
	using F=function<Monoid(Monoid, Monoid)>;
	int sz;
	vector<Monoid> seg;
	const F f;
	const Monoid e;

	SegmentTree(int n, const F f, const Monoid &e): f(f), e(e){
		sz=1;
		while(sz<n) sz<<=1;
		seg.resize(2*sz, e);
	}

	SegmentTree(int n, const F f, const Monoid &e, vector<Monoid> v): f(f), e(e){
		sz=1;
		while(sz<n) sz<<=1;
		seg.resize(2*sz, e);
		for(int i=0; i<n; i++) seg[i+sz]=v[i];
		for(int i=sz-1; i>=1; i--){
			seg[i]=f(seg[2*i], seg[2*i+1]);
		}
	}

	void update(int k, const Monoid &x){
		k+=sz;
		seg[k]=x;
		while(k>1){
			k>>=1;
			seg[k]=f(seg[2*k], seg[2*k+1]);
		}
	}

	Monoid query(int a, int b){
		a+=sz, b+=sz;
		Monoid ret=e;
		for(;a<b; a>>=1, b>>=1){
			if(b&1) ret=f(ret, seg[--b]);
			if(a&1) ret=f(ret, seg[a++]);
		}
		return ret;
	}

	template<typename C>
	int binarysearch(int st, C &check, Monoid &s, int k, int l, int r){//[st,ret):false, [st, ret+1):true (check(e):false)
		if(k>=sz){
			s=f(s, seg[k]);
			if(check(s)) return k-sz;
			else return -1;
		}
		int m=(l+r)>>1;
		if(m<=st) return binarysearch(st, check, s, 2*k+1, m, r);
		if(st<=l && !check(f(s, seg[k]))){
			s=f(s, seg[k]);
			return -1;
		}
		int vl=binarysearch(st, check, s, 2*k, l, m);
		if(vl!=-1) return vl;
		return binarysearch(st, check, s, 2*k+1, m, r);
	}
	
	template<typename C>
	int binarysearch(int st, C &check){
		Monoid s=e;
		return binarysearch(st, check, s, 1, 0, sz);
	}

	Monoid operator[](const int &k) const{
		return seg[k+sz];
	}
};
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    SegmentTree<int> seg(n, [](int x, int y){ return max(x, y);}, -1, a);
    while(q--){
        int t;
        scanf("%d", &t);
        if(t==1){
            int x, v;
            scanf("%d %d", &x, &v);
            x--;
            seg.update(x, v);
        }else if(t==2){
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            printf("%d\n", seg.query(l, r));
        }else{
            int x, v;
            scanf("%d %d", &x, &v);
            x--;
            auto check=[&](int a){ return a>=v;};
            int r=seg.binarysearch(x, check);
            if(r!=-1) printf("%d\n", r+1);
            else printf("%d\n", n+1);
        }
    }
    return 0;
}
