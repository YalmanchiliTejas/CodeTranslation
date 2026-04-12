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
vector<ll> build(ll K) {
    vector<ll> ans;

    ll d = K % 50;
    rep(i, 0, 50 - d) ans.push_back(49 - d);
    rep(i, 0, d) ans.push_back(50);

    ll a = K / 50;
    rep(i, 0, 50) ans[i] += a;

    return ans;
}

ll naive(vector<ll> A) {
    ll ans = 0;
    int n = A.size();
    while (1) {
        int ok = 1;
        rep(i, 0, n) if (n <= A[i]) ok = 0;
        if (ok) return ans;

        ans++;
        ll big = 0; int bigid = -1;
        rep(i, 0, n) if (big < A[i]) big = A[i], bigid = i;
        rep(i, 0, n) {
            if (i == bigid) A[i] -= n;
            else A[i]++;
        }
    }

    return ans;
}
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
    int N;

    while (cin >> N) {
        vector<ll> A;
        rep(i, 0, N) {
            ll x; cin >> x; A.push_back(x);
        }

        ll ans = count(A);
        cout << ans << endl;
        continue;

        ans = naive(A);
        cout << ans << endl;
    }
}