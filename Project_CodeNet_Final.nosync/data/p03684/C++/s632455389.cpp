#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 1e9+7;

struct UnionFind{

	std::vector<int> data;
	// dataの各要素について
	// 負の値:その集合のルートであること示す(spaghetti sourceではその絶対値は集合の要素数となっている)
	// 正の値:親ノードの番号(dataのインデックス)。root()を呼び出すたびに集合のルートを指すように書きなおされるので木はそんなに深くならない

	//初期化 size:最大要素数
	UnionFind(int size): data(size, -1){ }

	// 集合を併合する
	// すでに同じ集合だった場合は、falseが返る
	bool unite(int x, int y){
		x=root(x); y=root(y);
		if( x != y ){
			// yの属する集合のルートをxに変更
			data[y] = x;
		}
		return x!=y;
	}

	// 同じ集合かどうか判定
	bool find(int x, int y){
		return root(x) == root(y);
	}

	// 集合の識別番号を返す
	int root(int x){
		// 負の値を持つものがその集合のルート
		// 正の値は同じ集合に属するものを指す(辿ればいずれルートへ着く)
		return (data[x] < 0)? x : data[x]=root(data[x]);
	}

};


int main(){
	//ios_base::sync_with_stdio(0);
	int N, ans=0;
	ll x[100005], y[100005];
	vector<pair<pll,int>> vx, vy;

	cin >> N;
	rep(i,N){
		ll x, y;
		cin >> x >> y;
		vx.eb(pll(x, y), i);
		vy.eb(pll(y, x), i);
	}
	sort(all(vx));
	sort(all(vy));

	vector<pair<ll,pll>> v;
	rep(i,N-1){
		v.eb( vx[i+1].X.X - vx[i].X.X, pll(vx[i+1].Y, vx[i].Y) );
		v.eb( vy[i+1].X.X - vy[i].X.X, pll(vy[i+1].Y, vy[i].Y) );
	}
	sort(all(v));

	bool used[100005]={};
	UnionFind uf(N);
	for(auto t: v){
		int i = t.Y.X;
		int j = t.Y.Y;
		if( !uf.find(i, j) ){
			uf.unite(i,j);
			ans += t.X;
		}
	}

	cout << ans << endl;

	return 0;
}
