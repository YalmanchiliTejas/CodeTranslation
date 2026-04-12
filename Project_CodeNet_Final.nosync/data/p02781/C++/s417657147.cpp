#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;

string N;
int K;

ll dp[110][2][4];

ll rec(int i = 0, bool smaller = false, int k = K) {
    if (k == 0) return 1;
    if (i >= N.size()) return 0;

    ll &ret = dp[i][(int)smaller][k];
    if (ret > 0) return ret;
    ret = 0;

    if (smaller) {
        ret += rec(i + 1, true, k);            // 次の桁が0の時
        ret += rec(i + 1, true, k - 1) * 9LL;  // 次の桁が0以外の時
    } else {
        if (N[i] == '0') {  // 次の桁が0しかありえない時
            ret += rec(i + 1, false, k);
        } else {
            ret += rec(i + 1, true, k);                     // 次の桁が0の時
            ret += rec(i + 1, true, k - 1) * (N[i] - '1');  // 次の桁が0でもN[i]でも無い時
            ret += rec(i + 1, false, k - 1);                // 次の桁がN[i]の時
        }
    }
    return ret;
}

int main() {
    cin >> N;
    cin >> K;
    cout << rec() << endl;
    return 0;
}
