//インクルード(アルファベット順)
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<chrono>//実行時間計測
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm,accumulate
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//順序保持しないmap
#include<unordered_set>//順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;
//マクロ
//forループ
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define PI 3.14159265358979323846264338327950L

#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define FIND(v,key) std::find(v.begin(), v.end(), key) != v.end() //FIND(vector,key) :v contains key

#define int long long
#define Graph vector<vector<int> >
#define PII pair<int,int>
#define VI vector<int>
#define VVI vecotor<vector<int> >
#define VPII vector<pair<int,int> >

template<typename A, size_t N, typename T>

void Fill(A (&array)[N], const T &val) {
	std::fill( (T*)array, (T*)(array + N), val );
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ここにグローバル変数宣言
int H, W, sh, sw, gh, gw;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};//BFS関連


Graph G;

int N, M;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ここに関数宣言
int ctoi(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: return 0;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
signed main() {
	//入力の高速化用のコード
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cin >> N >> M;

	G.resize(N);


	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--; //ノートのインデックスを０始まり スタートも０始まり;
		G[a].PB(b);
		G[b].PB(a);
	}

	VI perm(N - 1); //順列を決定する配列

	FOR(i, 0, N - 2) {perm[i] = i + 1;} // perm[0]=1, perm[1]=2 perm[N-2]=N-1に注意


	int cnt = 0;

	do {
		bool ok = true;

		if ( FIND(G[0], perm[0]) == false ) {ok = false; continue;}

		FOR(i, 0, N - 3) {
			if ( FIND( G[perm[i]], perm[i + 1]) == false ) {ok = false; continue;}
		}

		if (ok) {cnt++;}

	} while ( next_permutation(perm.begin(), perm.end()) );


	cout << cnt << endl;























	return 0;




}





