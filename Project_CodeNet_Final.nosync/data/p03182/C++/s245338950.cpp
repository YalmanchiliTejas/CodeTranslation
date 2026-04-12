#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

/*遅延評価セグメント木*/
template<typename T,typename U=T>
class LazySegmentTree{
	using FX=function<T(T,T)>;
	using FA=function<T(T,U)>;
	using FM=function<U(U,U)>;
	using FP=function<U(U,int)>;
	int n,offset;	//n:=(数列の数（2の階乗数)),offset:=(オフセット(n-1)).
	const T ex;		//ex:=(モノイドXの単位元).
	const U em;		//em:=(モノイドMの単位元).
	vector<T> node;
	vector<U> lazy;
	const FX fx;	//fx:=(X ✕ X->X).
	const FA fa;	//fa:=(X ✕ M->X).
	const FM fm;	//fa:=(M ✕ M->M).
	const FP fp;	//fp:=(写像).
	
	int bufsize(int n_){		//bufsize:=(木の必要なノード数を返す).
		n=1;
		while(n<n_) n<<=1;
		offset=n-1;
		return 2*n-1;
	}
	void build(int l=0,int r=-1){//build:=(木を構築). O(N).
		if(r<0) r=n;
		l+=offset, r+=offset;
		do{
			l=(l-1)/2, r=(r-1)/2;
			for(int i=l;i<r;++i) node[i]=fx(node[2*i+1],node[2*i+2]);
		}while(l>0);
	}
	void eval(int k,int l,int r){//eval:=(k番目のノードについて遅延評価する).
		if(lazy[k]==em) return;
		node[k]=fa(node[k],fp(lazy[k],r-l));
		if(k<offset){//葉でなければ子に伝搬.
			lazy[2*k+1]=fm(lazy[2*k+1],lazy[k]);
			lazy[2*k+2]=fm(lazy[2*k+2],lazy[k]);
		}
		lazy[k]=em;
	}
	
public:
	/*Constructor.*/
	LazySegmentTree(int n_,T ex_,U em_,FX fx_,FA fa_,FM fm_,FP fp_)
	:ex(ex_),em(em_),fx(fx_),fa(fa_),fm(fm_),fp(fp_){
		int sz=bufsize(n_);
		node.assign(sz,ex), lazy.assign(sz,em);
	}
	LazySegmentTree(vector<T> &v_,T ex_,U em_,FX fx_,FA fa_,FM fm_,FP fp_)
	:ex(ex_),em(em_),fx(fx_),fa(fa_),fm(fm_),fp(fp_){
		int sz=bufsize(v_.size());
		node.assign(sz,ex), lazy.assign(sz,em);
		copy(ALL(v_),node.begin()+offset);//<algorithm>
		build();
	}
	
	void init(){fill(ALL(node),ex), fill(ALL(lazy),em);}	//init:=(初期化).
	void update(int a,int b,T x,int k=0,int l=0,int r=-1){	//update:=([a,b)間の要素をaに更新). O(log N).
		if(r<0) r=n;
		eval(k,l,r);
		if(b<=l or r<=a) return;
		if(a<=l and r<=b){
			lazy[k]=fm(lazy[k],x);
			eval(k,l,r);
		}else{
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			node[k]=fx(node[2*k+1],node[2*k+2]);
		}
	}
	/*query:=([a,b)間のクエリ結果を返す). O(log N).
	後ろの3つの引数は計算の簡単のための引数. kは節点の番号,lとrはその節点が[l,r)に対応づいているかを表す. したがって,外からはquery(a,b,0,0,n)と呼ぶ.*/
	T query(int a,int b,int k=0,int l=0,int r=-1){
		if(r<0) r=n;
		eval(k,l,r);
		if(b<=l or r<=a) return ex;			//[a,b)と[l,r)が交差しなければe.
		if(a<=l and r<=b) return node[k];	//[a,b)が[l,r)を完全に含んでいれば,この節点の値.
		T vl=query(a,b,2*k+1,l,(l+r)/2);
		T vr=query(a,b,2*k+2,(l+r)/2,r);
		return fx(vl,vr);					//交差する場合,2つの子をクエリ処理して比較.
	}
	
	typename vector<T>::reference operator[](int i){return node[i+offset];}
};

struct Ob{int l,a;};

//解説参考.
int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<Ob> > ob((int)n+1);
	REP(i,m){
		int l,r,a;
		cin>>l>>r>>a;
		ob[r].push_back({l,a});
	}
	
	using Type=llong;
	auto fx=[](Type a,Type b)->Type{return max(a,b);};
	auto fa=[](Type a,Type b)->Type{return a+b;};
	auto fm=[](Type a,Type b)->Type{return a+b;};
	auto fp=[](Type a,int len)->Type{return a;};
	LazySegmentTree<Type> tree(n+1,0,0,fx,fa,fm,fp);
	
	for(int i=1;i<=n;++i){
		tree.update(i,i+1,tree.query(0,i));
		for(auto elem:ob[i]) tree.update(elem.l,i+1,elem.a);
	}
	
	cout<<tree.query(0,n+1)<<endl;
}