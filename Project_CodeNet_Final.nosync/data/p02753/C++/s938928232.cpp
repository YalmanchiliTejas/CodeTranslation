#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
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
#define REP(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define REPD(i,n) for(ll (i)=(ll)(n)-1;(i)>=0;(i)--)
#define FOR(i,a,b) for(ll (i)=(a);(i)<=(b);(i)++)
#define FORD(i,a,b) for(ll (i)=(a);(i)>=(b);(i)--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second


//定数
constexpr ll INF = 1'010'000'000'000'000'017LL;

constexpr ll MOD = 1'000'000'007LL;

constexpr ll EPS = 1e-12;

constexpr ll PI = 3.14159265358979323846;

struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
        if(AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;

//----------------------------------------------------------

void solve(){
    char s[3];
    cin >> s[0] >> s[1] >> s[2];
    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

signed main(){
    solve();
    return 0;
}