//参考：https://qiita.com/DaikiSuyama/items/9dba963ba74396b9b7fd
//インクルード(アルファベット順)
#include <algorithm>     //sort,二分探索,など
#include <bitset>        //固定長bit集合
#include <cmath>         //pow,logなど
#include <complex>       //複素数
#include <deque>         //両端アクセスのキュー
#include <functional>    //sortのgreater
#include <iomanip>       //setprecision(浮動小数点の出力の誤差)
#include <iostream>      //入出力
#include <iterator>      //集合演算(積集合,和集合,差集合など)
#include <map>           //map(辞書)
#include <numeric>       //iota(整数列の生成),gcdとlcm(c++17)
#include <queue>         //キュー
#include <set>           //集合
#include <stack>         //スタック
#include <string>        //文字列
#include <unordered_map> //イテレータあるけど順序保持しないmap
#include <unordered_set> //イテレータあるけど順序保持しないset
#include <utility>       //pair
#include <vector>        //可変長配列

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())      //sizeをsize_tからllに直しておく
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007    //10^9+7:合同式の法
#define MAXR 100000       //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define FIR first    //pairの一つ目の要素
#define SEC second   //pairの二つ目の要素

signed main()
{
    //入力の高速化用のコード
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    REP(i, H)
    cin >> A[i];

    //予め移動した全部のマスの数を数え上げる
    ll count_all = 0;
    REP(i, H)
    REP(j, W)
    if (A[i][j] == '#')
        count_all++;

    //下に移動することを1、右に移動することを0で表現する
    REP(bf, 1 << H + W - 2)
    {
        ll cx = 0, cy = 0;
        ll current_count = count_all - 1; //初期位置は通過済み
        REP(k, H + W - 2)
        {
            //一つ下のマスに移動
            if (bf >> k & 1)
                cx++;
            //一つ右のマスに移動
            else
                cy++;

            //範囲外に出た場合はスキップ
            if (cx >= H || cy >= W)
                continue;

            //通過したかチェック
            if (A[cx][cy] == '#')
                current_count--;
        }

        //すべてのマスを通過できる移動パターンが見つかった場合
        if (current_count == 0)
        {
            cout << "Possible" << endl;
            return 0;
        }
    }

    cout << "Impossible" << endl;

    return 0;
}
