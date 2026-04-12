#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

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


const int NM = 100000;
ll A[NM];

ll MOD = 1000000007;


void solve() {
    string S;
    cin >> S;

    if (S == "AAA" || S == "BBB") {
        cout << "No";
   }
    else {
        cout << "Yes";
    }
}



int main() {
    solve();
    return 0;
}





