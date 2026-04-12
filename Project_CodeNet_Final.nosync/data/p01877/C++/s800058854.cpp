#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long Hash;

Hash hashV[500010];
Hash hashSum[500010];


long long MOD = INT_MAX;
struct LazySegmentTree{
	struct NODE{
		Hash val;
		Hash lazy;
		NODE(){
			val = lazy = 0;
		}
	};

	inline void lazy(int k,int a,int b){
		seg[k].val += (hashSum[b] - hashSum[a-1]) * seg[k].lazy;
		if( a != b){
			seg[k*2].lazy += seg[k].lazy;
			seg[k*2+1].lazy += seg[k].lazy;

		}
		seg[k].lazy = 0;
	}
	Hash merge(Hash a,Hash b){
		return a + b;
	}

	int n_;
	vector<NODE> seg;
	LazySegmentTree(int N){
		n_ = 1;
		while( n_ < N ) n_ *= 2;
		seg.resize(2*n_,NODE());
	}
	Hash get(int l,int r,int k,int a,int b){
		lazy(k,a,b);
		if( b < l || r < a ) return 0;
		if( l <= a && b <= r){
			return seg[k].val;
		}
		int m = (a+b)/2;
		return merge(get(l,r,k*2,a,m),get(l,r,k*2+1,m+1,b));
	}
	void add(int l,int r,int v,int k,int a,int b){
		lazy(k,a,b);
		if( b < l || r < a ) return;
		if( l <= a && b <= r ){
			seg[k].lazy = v;
			lazy(k,a,b);
			return;
		}
		int m = (a+b) / 2;
		add(l,r,v,k*2,a,m);
		add(l,r,v,k*2+1,m+1,b);
		seg[k].val = merge(seg[k*2].val,seg[k*2+1].val);
	}
	inline Hash get(int l,int r){
		return get(l,r,1,1,n_);
	}
	inline void add(int l,int r,Hash v){
		add(l,r,v,1,1,n_);
	}
};

int isp(long long n){
	for(long long i = 2 ; i*i <= n ; i++)
		if( n % i == 0 ) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	int mod = 1000000009;
	int prime = 1000000009;
	while( !isp(prime)) prime--;
	
	hashV[1] = 1;
	for(int i = 2 ; i <= N ; i++){
		hashV[i] = hashV[i-1] * mod;
	}
	for(int i = 1 ; i <= N ; i++)
		hashSum[i] = hashSum[i-1] + hashV[i];

	LazySegmentTree seg1(N);
	LazySegmentTree seg2(N);
	for(int i = 1 ; i <= N ; i++){
		int x;
		cin >> x;
		x += prime;
		seg1.add(i,i,x);
		seg2.add(N-i+1,N-i+1,x);
	}

	int Q;
	cin >> Q;

	while(Q--){
		int l,r,v;
		cin >> l >> r >> v;
		int L = N - r + 1;
		int R = N - l + 1;
		seg1.add(l,r,v);
		seg2.add(L,R,v);
		if( seg1.get(1,N) == seg2.get(1,N) ){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}

}