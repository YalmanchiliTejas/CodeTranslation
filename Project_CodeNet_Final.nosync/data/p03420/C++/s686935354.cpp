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
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/









ll N, K;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;

    if (K == 0) {
        ll ans = N * N;
        cout << ans << endl;
        return;
    }

    ll ans = 0;
    rep(b, K + 1, N + 1) {
        // K <= x % b

        // [K, b-1]
        // [K+b, 2b-1]

        // nb-1=N
        // nb = N + 1
        // n = (N + 1) / b

        ll n = (N + 1) / b;
        ll d = 0;
        
        d += 1LL * (b - K) * n;
        
        ll L = K + b * n;
        ll R = N;
        if (L <= R) d += R - L + 1;

        //printf("%d -> %lld\n", b, d);
        ans += d;
    }

    cout << ans << endl;
}