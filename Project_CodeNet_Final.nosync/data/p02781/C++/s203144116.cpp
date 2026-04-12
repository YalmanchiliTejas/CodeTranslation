#include<algorithm>
#include<algorithm>     //sort,二分探索,など
#include<bitset>        //固定長bit集合
#include<cmath>         //pow,logなど
#include<complex>       //複素数
#include<deque>         //両端アクセスのキュー
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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvld;
typedef vector<vector<string>> vvs;
typedef vector<vector<bool>> vvb;
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//dp[i][j][k] := 数字を先頭からi桁決めたときの、0以外の数字がちょうどk個出ている数字の個数（jは未満フラグ）
ll dp[101][2][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    int K;
    cin >> K;

    dp[0][0][0] = 1;

    rep(i, N.size())
    {
        int d = N[i] - '0';

        reple(smaller, 0, 1)
        {
            reple(j, 0, K)
            {
                for (int x = 0; x <= (smaller ? 9 : d); x++)
                {
                    //0でない数字がK個以上出現した場合は数えない
                    if (j == K && x != 0) continue;
                    dp[i + 1][smaller || x < d][(x ? j + 1 : j)] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;

    return 0;
}