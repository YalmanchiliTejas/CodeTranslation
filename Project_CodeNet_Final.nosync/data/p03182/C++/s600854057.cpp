#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433;

template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

template<class typeNode, class typeLazy, class Operator> class LazySegmentTree {
	size_t length;                                       //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	size_t height;                                       //セグメント木の高さ 
	typeNode unitNode;                                   //nodeの単位元
	typeLazy unitLazy;                                   //lazyの単位元
	vector<typeNode> node;                               //node
	vector<typeLazy> lazy;                               //lazy
	vector<int> width;                                   //width
    Operator Op;

public:

	//同じinitで初期化
	LazySegmentTree(const size_t num, const typeNode unitNode, const typeLazy unitLazy, const typeNode init)
    : unitNode(unitNode), unitLazy(unitLazy) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	//unitで初期化
	LazySegmentTree(const size_t num, const typeNode unitNode, const typeLazy unitLazy)
    : unitNode(unitNode), unitLazy(unitLazy) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = unitNode;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	//vectorで初期化
	LazySegmentTree(const vector<typeNode>& vec, const typeNode unitNode, const typeLazy unitLazy)
	 : unitNode(unitNode), unitLazy(unitLazy) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}


	void propagate(int k) {
		if(lazy[k] == unitLazy) return;
		node[k] = Op.funcMerge(node[k],lazy[k],width[k]);
		if(k < length) lazy[2*k+0] = Op.funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Op.funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = unitLazy;
    }


	//idx : 0-indexed
    void update(int a, int b, typeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Op.funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Op.funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == unitLazy) node[l] = Op.funcNode(Op.funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],width[(l<<1)+0]),Op.funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],width[(l<<1)+1]));
			if(lazy[r] == unitLazy) node[r] = Op.funcNode(Op.funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],width[(r<<1)+0]),Op.funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],width[(r<<1)+1]));
		}
    }

	//[l,r)
	typeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		typeNode vl = unitNode, vr = unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Op.funcNode(vl,Op.funcMerge(node[l],lazy[l],width[l])),l++;
			if(r&1) r--,vr = Op.funcNode(Op.funcMerge(node[r],lazy[r],width[r]),vr);
		}
		return Op.funcNode(vl,vr);
	}

	void print(){
		cout << "node" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		cout << "lazy" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << lazy[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		// cout << "width" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << width[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		// cout << "vector" << endl;
		// cout << "{ " << get(0,1);
		// for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		// cout << " }" << endl;
	}

};

//node:総和　lazy:加算
template<class typeNode, class typeLazy> struct nodeSumLazyAdd {
	typeNode funcNode(typeNode l,typeNode r){
        return l+r;
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return l+r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return l+r*len;
    }
    //example
    //LazySegmentTree<ll,ll,nodeSumLazyPlus<ll,ll>> Seg(N,0,0,0);
};

//node:最小　lazy:加算
template<class typeNode, class typeLazy> struct nodeMinLazyAdd {
	typeNode funcNode(typeNode l,typeNode r){
        return min(l,r);
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return l+r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return l+r;
    }
    //example
    //LazySegmentTree<ll,ll,nodeMinLazyAdd<ll,ll>> Seg(N,inf,0,0);
	//verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
};

//node:最小　lazy:加算
template<class typeNode, class typeLazy> struct nodeMaxLazyAdd {
	typeNode funcNode(typeNode l,typeNode r){
        return max(l,r);
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return l+r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return l+r;
    }
    //example
    //LazySegmentTree<ll,ll,nodeMaxLazyAdd<ll,ll>> Seg(N,inf,0,0);
};

//node:GCD　lazy:更新
template<class typeNode, class typeLazy> struct nodeGCDLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return ((r == 0) ? l : funcNode(r, l % r));
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=0?r:l;
    }
    //example
    //LazySegmentTree<ll,ll,nodeGCDLazyUpdate<ll,ll>> Seg(A,0,0);
    //verify https://atcoder.jp/contests/abc125/tasks/abc125_c
};

//node:総和　lazy:更新
template<class typeNode, class typeLazy> struct nodeSumLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return l+r;
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=-2000?r*len:l;
    }
    //example
	//LazySegmentTree<ll,ll,nodeSumLazyUpdate<ll,ll>> Seg(N,0,-2000,0);
    //verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
};

//node:最大　lazy:更新
template<class typeNode, class typeLazy> struct nodeMaxLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return max(l,r);
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=0?r*len:l;
    }
    //example
	//LazySegmentTree<ll,ll,nodeMaxLazyUpdate<ll,ll>> Seg(N+2,0,0);
    //verify https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d
};

//node:最大　lazy:更新
template<class typeNode, class typeLazy> struct nodeMinLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return min(l,r);
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=0?r*len:l;
    }
    //example
	//LazySegmentTree<ll,ll,nodeMinLazyUpdate<ll,ll>> Seg(N,HIGHINF,0);
    //verify https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e
};

//node:mod和　lazy:mod加算
template<class typeNode, class typeLazy> struct nodeModSumLazyModAdd {
	typeNode funcNode(typeNode l,typeNode r){
        return (l+r)%MOD;
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return (l+r)%MOD;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return (l+(r*len)%MOD)%MOD;
    }
    //example
	//LazySegmentTree<ll,ll,nodeMinLazyUpdate<ll,ll>> Seg(N,HIGHINF,0);
    //verify https://atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_d
};

int main() {
	int N,M; cin >> N >> M;
	vector<ll> L(M),R(M),A(M);
	vector<vector<int>> edge(N+1);
	for(int i = 0; i < M; ++i) {
		cin >> L[i] >> R[i] >> A[i];
		edge[R[i]].push_back(i);
	}
	LazySegmentTree<ll,ll,nodeMaxLazyAdd<ll,ll>> dp(N+1,0,0);
	for(int i = 1; i <= N; ++i) {
		ll maxi = dp.get(0,i);
		dp.update(i,i+1,maxi);
		for(int j:edge[i]){
			dp.update(L[j],R[j]+1,A[j]);
		}
	}
	cout << dp.get(0,N+1) << endl;
    return 0;
}