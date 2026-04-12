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

#define rep(i,n) for (int i = 0; i < n; i++)
#define REP(i,n) for(int i=1;i<=n;i++)

using namespace std;
typedef long long ll;

int main()
{
    const ll MOD = 1000000007;

    // Input
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;

    rep(i, n) {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }

    ll ans = 0;

    rep(i, n - 1) {
        sum -= a[i];

        if (sum < 0) sum += MOD;

        ans += a[i] * sum % MOD;
   }
    cout << ans % MOD;

    return 0;
}
