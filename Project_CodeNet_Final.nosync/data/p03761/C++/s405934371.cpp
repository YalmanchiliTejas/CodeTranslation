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

    ll n;
    cin >> n;
    vector<string> S(n);
    vector<string::iterator> SI(n);

    REP(i, n)
    {
        cin >> S[i];
        sort(ALL(S[i]));
        SI[i] = S[i].begin();
    }

    char max_char = 'a';
    string sub_string = "", ans = "";
    bool is_continue = true;
    while (is_continue)
    {
        //まず今の位置における最大のアルファベットを求める
        REP(i, n)
        {
            if (max_char < *SI[i])
                max_char = *SI[i];
        }

        //最大値との相違がないか確かめる
        bool is_changed = false;
        REP(i, n)
        {
            if (max_char != *SI[i])
            {
                is_changed = true;
                break;
            }
        }

        //最大値との相違がなければ一つ進める
        if (!is_changed)
        {
            REP(i, n)
            {
                ++SI[i];
            }
            sub_string.PB(max_char);
        }
        //最大値との相違があれば、部分文字列は消滅
        else
        {
            ans += sub_string;
            sub_string = "";
            REP(i, n)
            {
                if (max_char > *SI[i])
                    ++SI[i];
            }
        }

        //いずれかの文字列が最後に到達したら終了
        REP(i, n)
        {
            if (SI[i] == S[i].end())
            {
                ans += sub_string;
                is_continue = false;
                break;
            }
        }
    }

    sort(ALL(ans));
    cout << ans << endl;

    return 0;
}
