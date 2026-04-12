#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int const MD=int(1e9)+7;
int const MAXN=220000;
int f[MAXN];
int fi[MAXN];
int madd(int x,int y) {
	if (x+y<MD) return x+y; else return x+y-MD;
}
int mmul(int x,int y) {
	return int(ll(x)*y % MD);
}
int mpow(int x,int p) {
	int res=1;
	while (p>0) {
		if (p%2) res=mmul(res,x);
		x=mmul(x,x);
		p/=2;
	}
	return res;
}
int mcomb(int n,int k) {
	return mmul(f[n],mmul(fi[k],fi[n-k]));
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);
	
	f[0]=fi[0]=1;
	rep(i,1,MAXN) {
		f[i]=mmul(f[i-1],i);
		fi[i]=mpow(f[i],MD-2);
	}

	int N,M,K;
	cin>>N>>M>>K;
	
	int res=0;
	rep(d,1,N) res=madd(res,mmul(mmul(d,N-d),mmul(M,M)));
	rep(d,1,M) res=madd(res,mmul(mmul(d,M-d),mmul(N,N)));
	res=mmul(res,mcomb(N*M-2,K-2));
	
	cout<<res<<"\n";
}
