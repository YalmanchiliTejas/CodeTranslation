
#include<algorithm>     //sort,二分探索,など
#include<bitset>        //固定長bit集合
#include<cmath>         //pow,logなど
#include<complex>       //複素数
#include<deque>         //両端アクセスのキュー
#include<fstream>       //ファイルストリーム（標準入力変更用）
#include<functional>    //sortのgreater
#include<iomanip>       //setprecision(浮動小数点の出力の誤差)
#include<iostream>      //入出力
#include<iterator>      //集合演算(積集合,和集合,差集合など)
#include<map>           //map(辞書)
#include<numeric>       //iota(整数列の生成),gcdとlcm(c++17)
#include<queue>         //キュー
#include<set>           //集合
#include<stack>         //スタック
#include<string>        //文字列
#include<unordered_map> //イテレータあるけど順序保持しないmap
#include<unordered_set> //イテレータあるけど順序保持しないset
#include<utility>       //pair
#include<vector>        //可変長配列

//名前
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef map<string, int> msi;
typedef map<string, ll> msll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<string>> vvs;
typedef vector<vector<bool>> vvb;

//定数
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;

//マクロ
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,e) for(int i=s;i<e;i++)
#define repse(i,s,e) for(int i=s;i<=e;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define in1(x1) cin >> x1
#define in2(x1, x2) cin >> x1 >> x2
#define in3(x1, x2, x3) cin >> x1 >> x2 >> x3
#define inN(x, N) rep(i, N) in1(x[i])
#define outl(x) cout << x << endl
#define out2l(x, y) cout << x << " " << y << endl 

//よく使う関数
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //標準入力をファイルに変更
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());

    int X;
    in1(X);

    if (X == 7 || X == 5 || X == 3)
    {
        outl("YES");
    }
    else
    {
        outl("NO");
    }

    return 0;
}
