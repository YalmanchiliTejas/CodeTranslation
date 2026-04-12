
#include <algorithm>  //sort,二分探索,など
#include <array>
#include <bitset>         //固定長bit集合
#include <cmath>          //pow,logなど
#include <complex>        //複素数
#include <deque>          //両端アクセスのキュー
#include <functional>     //sortのgreater
#include <iomanip>        //setprecision(浮動小数点の出力の誤差)
#include <iostream>       //入出力
#include <map>            //map(辞書)s
#include <numeric>        //iota(整数列の生成),gcdとlcm(c++17)
#include <queue>          //キュー
#include <set>            //集合
#include <stack>          //スタック
#include <string>         //文字列
#include <unordered_map>  //イテレータあるけど順序保持しないmap
#include <unordered_set>  //イテレータあるけど順序保持しないset
#include <utility>        //pair
#include <vector>         //可変長配列

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end()  // sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())  // sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main() {
  string s;
  cin >> s;
  if (s[0] == s[1] && s[1] == s[2]) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}