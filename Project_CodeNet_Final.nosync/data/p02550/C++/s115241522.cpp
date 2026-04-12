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

template<typename T>
class SegmentTree{
	using F=function<T(T,T)>;
	int n,offset;	//n:=(葉の数（2の階乗数）),offset:=(n-1).
	const T e;		//e:=(単位元).
	vector<T> node;
	const F f;		//f:=(二項演算処理).
	
	int bufsize(int n_){//木に必要なノード数を返す.
		n=1;
		while(n<n_) n<<=1;
		offset=n-1;
		return 2*n-1;
	}
	void build(int l=0,int r=-1){//木を構築する. O(N).
		if(r<0) r=n;
		l+=offset, r+=offset;
		do{
			l=(l-1)/2, r=(r-1)/2;
			for(int i=l;i<r;++i) node[i]=f(node[2*i+1],node[2*i+2]);
		}while(l>0);
	}
	
public:
	/*constructor.*/
	SegmentTree(int n_,T e_,F f_):node(bufsize(n_),e_),e(e_),f(f_){}
	SegmentTree(const vector<T> &v_,T e_,F f_):node(bufsize(v_.size()),e_),e(e_),f(f_){
		copy(ALL(v_),node.begin()+offset);//<algorithm>.
		build();
	}
		
	void init(){fill(ALL(node),e);}//初期化する.
	void update(int k,T a){//k番目の要素をaに更新する. O(log N).
		k+=offset;
		node[k]=a;
		while(k>0){
			k=(k-1)/2;//parent.
			node[k]=f(node[2*k+1],node[2*k+2]);
		}
	}
	void add(int k,T a){update(k,node[k+offset]+a);}//k番目の要素にaを加算する.
	/*[a,b)間のクエリ結果を返す. O(log N).
	（後ろの3つの引数は計算の簡単のための引数. kはノード番号,lとrはそのノードが[l,r)に対応づいているかを表す. 外からはquery(a,b,0,0,n)と呼ぶ.）*/
	T query(int a,int b,int k=0,int l=0,int r=-1){
		if(r<0) r=n;
		if(b<=l or r<=a) return e;			//[a,b)と[l,r)が交差しなければe.
		if(a<=l and r<=b) return node[k];	//[a,b)が[l,r)を完全に含んでいれば,この節点の値.
		T vl=query(a,b,2*k+1,l,(l+r)/2);
		T vr=query(a,b,2*k+2,(l+r)/2,r);
		return f(vl,vr);					//交差する場合,2つの子をクエリ処理して比較.
	}
	
	typename vector<T>::reference operator[](int i){return node[i+offset];}
};

int main(){
	llong n;
	int x,m;
	cin>>n>>x>>m;
	
	vi next(m);
	REP(i,m) next[i]=(llong)i*i%m;
	
	int p=x;
	vl v;
	vi seen(m,-1);
	for(int i=0;;++i){
		v.push_back(p);
		seen[p]=i;
		
		p=next[p];
		if(seen[p]>=0) break;
	}
	
	llong ans=0LL;
	if(n<=seen[p]){
		REP(i,n){
			ans+=x;
			x=next[x];
		}
	}else{
		using Type=llong;
		auto f=[](Type a,Type b)->Type{return a+b;};
		SegmentTree<Type> tree(v,0LL,f);
		
		ans+=tree.query(0,seen[p]);
		n-=seen[p];
		ans+=tree.query(seen[p],v.size())*(n/(v.size()-seen[p]));
		ans+=tree.query(seen[p],seen[p]+n%(v.size()-seen[p]));
	}
	
	cout<<ans<<endl;
	return 0;
}