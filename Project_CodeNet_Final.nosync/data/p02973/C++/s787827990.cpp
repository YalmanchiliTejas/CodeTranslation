#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif
struct segtree{
	using D = int;
	D inf = 1e9;

	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,-inf);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,-inf);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = max(val[i*2],val[i*2+1]);
	}
	void changemax(int k,D d){
		k+=N;
		chmax(val[k],d);
		k/=2;
		while(k){
			val[k] = max(val[k*2],val[k*2+1]);
			k/=2;
		}
	}
	D getmax(int a,int b){
		D res = -inf;
		a+=N,b+=N;
		while(a<b){
			if(a&1) chmax(res,val[a++]);
			if(b&1) chmax(res,val[--b]);
			a/=2,b/=2;
		}
		return res;
	}
};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
	int N;
	cin >> N;
	V<int> A(N);
	rep(i,N) cin >> A[i];
	{
		V<int> as = A;
		sort(all(as));
		as.erase(unique(all(as)),as.end());
		rep(i,N) A[i] = lower_bound(all(as),A[i]) - as.begin();
	}
	segtree seg(V<int>(N,0));
	int len = 0;
	rep(i,N){
		int v = seg.getmax(A[i],N) + 1;
		seg.changemax(A[i],v);
		chmax(len,v);
	}
	cout << len << endl;
}
