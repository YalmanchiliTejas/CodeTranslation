#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　 |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/



string S;
//---------------------------------------------------------------------------------------------------
int check(int i, int j) { // S[i..j]
    if (S[i] == '0') {
        int len = j - i + 1;
        if (len == 1) return 1;
        return 0;
    }

    int sm = 0;
    rep(k, i, j + 1) sm = sm * 10 + S[k] - '0';
    return sm <= 255;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> S;
    int N = S.length();
    int ans = 0;
    rep(a, 1, N) rep(b, a + 1, N) rep(c, b + 1, N) {
        if (check(0, a - 1) and check(a, b - 1) and check(b, c - 1) and check(c, N - 1)) ans++;
    }
    cout << ans << endl;
}

