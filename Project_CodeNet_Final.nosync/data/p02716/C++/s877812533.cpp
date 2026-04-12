#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000000
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
#define LOGMAXR 18 // floor(log2(10^5)) + 1: 配列の最大のrangeのlog
//略記
//#define PB push_back //vectorヘの挿入
//#define MP make_pair //pairのコンストラクタ
//#define F first //pairの一つ目の要素
//#define S second //pairの二つ目の要素

ll max(ll a, ll b){
  if(a > b) return a;
  return b;
}

int main(){
  ll N;
  cin >> N;
  ll A[N];
  REP(i, N) cin >> A[i];
  ll cnt_sel[N][3], cnt_skip[N][3];
  cnt_sel[0][0] = A[0];
  cnt_sel[0][1] = -INF;
  cnt_sel[0][2] = -INF;
  cnt_skip[0][0] = -INF;
  cnt_skip[0][1] = 0;
  cnt_skip[0][2] = -INF;
  REP(i, N - 1){
    cnt_sel[i + 1][0] = cnt_skip[i][0] + A[i + 1];
    cnt_sel[i + 1][1] = cnt_skip[i][1] + A[i + 1];
    cnt_sel[i + 1][2] = cnt_skip[i][2] + A[i + 1];
    cnt_skip[i + 1][0] = cnt_sel[i][0];
    cnt_skip[i + 1][1] = max(cnt_sel[i][1], cnt_skip[i][0]);
    cnt_skip[i + 1][2] = max(cnt_sel[i][2], cnt_skip[i][1]);
    // cout << cnt_sel[i + 1][0] << " "
    // 	 << cnt_sel[i + 1][1] << " "
    // 	 << cnt_sel[i + 1][2] << " "
    // 	 << cnt_skip[i + 1][0] << " "
    // 	 << cnt_skip[i + 1][1] << " "
    // 	 << cnt_skip[i + 1][2] << endl;
  }
  if(N % 2){ // 奇数
    cout << max(cnt_sel[N - 1][2], cnt_skip[N - 1][1]) << endl;
  }else{
    cout << max(cnt_sel[N - 1][1], cnt_skip[N - 1][0]) << endl;
  }
  return 0;
}
