#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL-1
double EPS=1e-9;
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef complex<double> P;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
long long int MOD = 1000000007;
/*
cin >> n;
vi a(n);
rep(i,n)cin>>a[i];
*/template <typename T>
struct LazySegmentTree {
    int n;
    vector<T> data;
    vector<T> lazy;
    T INITIAL_DATA_VALUE;
    T INITIAL_LAZY_VALUE;

    //以下が三つの演算
    static T merge(T x, T y);
    void updateNode(int k, T x);
    void apply(int k, int seg_len);
 
    void init(int size, T initial_data_value, T initial_lazy_value) {
        n = 1;
        INITIAL_DATA_VALUE = initial_data_value;
        INITIAL_LAZY_VALUE = initial_lazy_value;
        while (n < size) n *= 2;
        data.resize(2 * n - 1, INITIAL_DATA_VALUE);
        lazy.resize(2 * n - 1, INITIAL_LAZY_VALUE);
    }
 
    LazySegmentTree(int size, T initial_data_value, T initial_lazy_value) {
        init(size, initial_data_value, initial_lazy_value);
    }
 
    LazySegmentTree(int size, T initial_value) {
        init(size, initial_value, initial_value);
    }
 
    T getLeaf(int k) {
        return data[k + n - 1];
    }
 
    void eval(int k, int l, int r) {
        if (lazy[k] == INITIAL_LAZY_VALUE) return;
        apply(k, r - l);
        if (r - l > 1) {
            updateNode(2 * k + 1, lazy[k]);
            updateNode(2 * k + 2, lazy[k]);
        }
        lazy[k] = INITIAL_LAZY_VALUE;
    }
 
    //区間[a, b)に対する更新
    //k:節点番号, [l, r):節点に対応する区間
    void update(int a, int b, T x, int k, int l, int r) {
        eval(k, l, r);
        //[a, b)と[l, r)が交差しない場合
        if (r <= a || b <= l) return;
        //[a, b)が[l, r)を含む場合、節点の値
        if (a <= l && r <= b) {
            updateNode(k, x);
            eval(k, l, r);
        } else {
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            data[k] = merge(data[2 * k + 1], data[2 * k + 2]);
        }
    }
 
    void update(int a, int b, T x) {
        update(a, b, x, 0, 0, n);
    }
 
    //[a, b)に対するクエリに応答
    //k:節点番号, [l, r):節点に対応する区間
    T query(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        //[a, b)と[l, r)が交差しない場合
        if (r <= a || b <= l) return INITIAL_DATA_VALUE;
        //[a, b)が[l, r)を含む場合、節点の値
        if (a <= l && r <= b) return data[k];
        else {
            //二つの子をマージ(モノイド演算)
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }
    }
 
    //外から呼ぶ時 デフォルト値にしてもよい。
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};
 
//この三つの演算をいじくる。作用素とモノイド？
template <typename T>
T LazySegmentTree<T>::merge(T x, T y) {
    return max(x, y);
}
 
template <typename T>
void LazySegmentTree<T>::updateNode(int k, T x) {
    lazy[k] += x;
}
 
template <typename T>
void LazySegmentTree<T>::apply(int k, int seg_len) {
    data[k] += lazy[k];
}
int N,M;
int main(){

	cin>>N>>M;
	vpii lfromr[214514];
	vi val;
	rep(i,M){
		int l,r;
		ll x;
		cin>>l>>r>>x;
		val.pb(x);
		lfromr[r].pb(mp(l,i));
		
	}
	LazySegmentTree<ll> seg(N+1,0);
	for(int i=1;i<=N;i++){
		ll ma=seg.query(1,i+1);
		seg.update(i, i+1, ma);
		rep(j,lfromr[i].size()){
			seg.update(lfromr[i][j].first, i+1, val[lfromr[i][j].second]);
		}
	}
	//rep(i,N+1)cout<<seg.query(i,i+1)<<endl;
	cout<<seg.query(0,N+1)<<endl;
}