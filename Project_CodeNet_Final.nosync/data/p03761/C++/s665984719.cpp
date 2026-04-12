#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x) // decltypeで型取得、引数があればva_argsのところに入れる
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 1e9;
const int MOD = 1000000007; // 計算してからmodで割る ans = (ans * a) % mod
#define int long long
template <typename T = long long > T in () { T x; cin >> x; return(x);}
// int a = in() のように使うlong long以外の型の時はstirng s = in<string>()のように型を指定する

signed main(void){
    int n; cin >> n;
    vector<int> num(26), ans(26, INF);
    REP(i, n){
        string s; cin >> s;
        REP(j, s.size()) num[s[j] - 'a']++;
        REP(j, 26) ans[j] = min(ans[j], num[j]);
        REP(j, 26) num[j] = 0;
    }

    REP(i, 26){
        REP(j, ans[i]) cout << char(i + 'a');
    }
    cout << endl;
}