#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
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
 
 
 
 
 
 
typedef long long ll;
#define INF 1LL<<60
ll count(vector<ll> A) {
    int n = A.size();
    ll ans = 0;
    while (1) {
        ll mi = INF, ma = 0;
        rep(i, 0, n) {
            mi = min(mi, A[i]);
            ma = max(ma, A[i]);
        }
 
        if (ma < n) return ans;
 
        if (n <= mi) {
            ll d = mi - n + 1;
            ans += 1LL * d * n;
            rep(i, 0, n) A[i] -= d;
        } else {
            ll d = ma / n;
            ans += d;
            int id = -1;
            rep(i, 0, n) if (A[i] == ma) id = i;
            rep(i, 0, n) {
                if (i == id) A[i] -= d * n;
                else A[i] += d;
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    int N; cin >> N;

    vector<ll> A;
    rep(i, 0, N) {
        ll x; cin >> x; A.push_back(x);
    }

    ll ans = count(A);
    cout << ans << endl;
}