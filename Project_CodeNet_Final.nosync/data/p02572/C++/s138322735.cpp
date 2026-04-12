#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
#define SZ(v)      ((int)(v).size())
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

/*Binary Indexed Tree*/
template<typename Type>
struct BIT{
	int n;				//n:=(要素数).
	vector<Type> dat;	//i:=[1,n].
	
	/*constructor.*/
	BIT(int n_):n(n_),dat(n_+1,0){}
	BIT(vector<Type> &v_):n(v_.size()),dat(v_.size()+1){
		copy(ALL(v_),dat.begin()+1);
		build();
	}
	
	void build(){//木を構築する. O(N).
		for(int i=1;i<n;++i){
			if(i+(i&-i)<=n) dat[i+(i&-i)]+=dat[i];
		}
	}
	void init(Type x=0){//全要素をxで初期化する. O(N).
		fill(dat.begin()+1,dat.end(),x);
		if(x==0) return;
		build();
	}
	void add(int i,Type x){//i番目の要素にxを足す. O(log N).
		if(i<=0 or n<i) return;
		for(;i<=n;i+=(i&-i)) dat[i]+=x;
	}
	Type sum(int i){//[1,i]間の和を求める. O(log N).
		if(i<=0 or n<i) return 0;
		Type res=0;
		for(;i>0;i-=(i&-i)) res+=dat[i];
		return res;
	}
	Type range_sum(int l,int r){return sum(r)-sum(l-1);}//[l,r]間の和を求める.
};

int main(){
	int n;
	cin>>n;
	
	vector<llong> a(n);
	REP(i,n) cin>>a[i];
	
	llong ans=0LL;
	BIT<llong> tree(a);
	FOR(i,1,n){
		llong sum=tree.range_sum(i+1,n)%MOD;
		ans=(ans+a[i-1]*sum%MOD)%MOD;
	}

	cout<<ans<<endl;
}

