#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

// init {{{
struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
        if (AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;


const int NM = 101001;//ここを問題の制約を見ながらいじる．配列の確保に使う．
ll X[NM];//あまり褒められたことではないが関数の外側に配列を確保すると怒られにくい．

       // Main program
void solve() {
    ll  N,M;
    cin >> N;
    cin >> M;

    if (N == M) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

       
    return;

}

int main() {
    solve();
    return 0;
}





