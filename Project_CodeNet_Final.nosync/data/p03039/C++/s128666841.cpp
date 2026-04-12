#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int const MD=int(1e9)+7;
int const MAXNM=220000;

inline int madd(int x,int y) {
	if (x+y<MD) return x+y; else return x+y-MD;
}
inline int msub(int x,int y) {
	if (x-y>=0) return x-y; else return x-y+MD;
}
inline int mmul(int x,int y) {
	return int(ll(x)*y % MD);
}
int mpow(int x,int y) {
	int res=1;
	while (y>0) {
		if (y%2) res=mmul(res,x);
		x=mmul(x,x);
		y/=2;
	}
	return res;
}
inline int minv(int x) {
	return mpow(x,MD-2);
}

int fact[MAXNM];
int invfact[MAXNM];
void mfact_init() {
	fact[0]=invfact[0]=1;
	rep(i,1,MAXNM) {
		fact[i]=mmul(fact[i-1],i);
		invfact[i]=minv(fact[i]);
	}
}
inline int mcomb(int x,int y) {
	if (x<y) return 0;
	return mmul(fact[x],mmul(invfact[x-y],invfact[y]));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);

	mfact_init();

	int N,M,K;
	cin>>N>>M>>K;
	
	int res=0;
	
	int c=mcomb(N*M-2,K-2);
	rep(dx,1,N) res=madd(res,mmul(c,mmul(dx,mmul(N-dx,mmul(M,M)))));
	rep(dy,1,M) res=madd(res,mmul(c,mmul(dy,mmul(M-dy,mmul(N,N)))));
	
	cout<<res<<"\n";
}
