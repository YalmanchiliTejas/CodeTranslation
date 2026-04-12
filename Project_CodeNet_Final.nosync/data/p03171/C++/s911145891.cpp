#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/











int N; ll A[3010];
//---------------------------------------------------------------------------------------------------
int vis[3010][3010];
ll memo[3010][3010];
ll dp(int L, int R) {
    if (L > R) return 0;
    if (vis[L][R]) return memo[L][R];
    vis[L][R] = 1;

    int diff = N - (R - L + 1);

    ll res = 0;
    if (diff % 2 == 0) {
        // X-Yを最大化したい
        res = -infl;
        chmax(res, dp(L + 1, R) + A[L]);
        chmax(res, dp(L, R - 1) + A[R]);
    } else {
        // X-Yを最小化したい
        res = infl;
        chmin(res, dp(L + 1, R) - A[L]);
        chmin(res, dp(L, R - 1) - A[R]);
    }

    return memo[L][R] = res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    cout << dp(0, N - 1) << endl;
}
