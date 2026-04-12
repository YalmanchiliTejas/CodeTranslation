#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x) // decltypeで型取得、引数があればva_argsのところに入れる
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 1e9;
const double PI = 3.1415926535;
const int MOD = 1000000007; // 計算してからmodで割る ans = (ans * a) % mod
#define int long long
template <typename T = long long > T in () { T x; cin >> x; return(x);}
// int a = in() のように使うlong long以外の型の時はstirng s = in<string>()のように型を指定する

signed main(void){
    int a, b, c; cin >> a >> b >> c;
    int x, y; cin >> x >> y;
    int ans = INF;
    if(a + b <= c * 2){
        ans = a * x + b * y;
    }else{
        int many;
        if(x < y) many = b;
        else many = a;

        ans = c * max(x, y) * 2;
        ans = min(ans, c * min(x, y) * 2 + abs(x - y) * many);
    }
    cout << ans << endl;
}