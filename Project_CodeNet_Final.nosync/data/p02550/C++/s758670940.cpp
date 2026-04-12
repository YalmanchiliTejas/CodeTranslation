#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
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

using vl   = vector<long long>;
using vvl  = vector<vl >;
using vvvl = vector<vvl >;

/*Binary Indexed Tree*/
template<typename Type>
struct BIT{//区間和クエリ（RSQ:Range Sum Query）をO(log N)で行う.
	int n;				//n:=(要素数).
	vector<Type> dat;	//i:=[1,n].
	
	/*constructor.*/
	BIT(int n_):n(n_),dat(n_+1,0){}
	BIT(const vector<Type> &v_):n(v_.size()),dat(v_.size()+1){
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
		assert(1<=i and i<=n);
		for(;i<=n;i+=(i&-i)) dat[i]+=x;
	}
	Type sum(int i){//[1,i]間の和を求める. O(log N).
		if(i<1 or n<i) return 0;
		Type res=0;
		for(;i>0;i-=(i&-i)) res+=dat[i];
		return res;
	}
	Type range_sum(int l,int r){//[l,r]間の和を求める(RSQ).
		if(l>r) return 0;
		return sum(r)-sum(l-1);
	}
};

int main(){
	llong n,x,m;
	cin>>n>>x>>m;
	
	vl v;
	vi seen(m,-1);//seen[i]:=(iが最初に出てくる順番).
	for(int i=1;;++i){
		v.push_back(x);
		seen[x]=i;
		x=x*x%m;
		if(seen[x]>=0) break;
	}
	
	BIT<llong> tree(v);
	
	llong ans=0LL;
	if(n<=v.size()) ans+=tree.range_sum(1,n);
	else{
		int range=v.size()-seen[x]+1;//ループ範囲の長さ.
		ans+=tree.range_sum(1,seen[x]-1);
		n-=seen[x]-1;
		ans+=tree.range_sum(seen[x],v.size())*(n/range);
		ans+=tree.range_sum(seen[x],seen[x]+n%range-1);
	}
	
	cout<<ans<<endl;
}