#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;

int main() {
    string N;
    cin >> N;
    int K;
    cin >> K;
    ll n = (ll)N.size();

    vector<int> keta, val;
    REP(i, n) {
        if (N[i] != '0') {
            keta.push_back(n - i - 1);
            val.push_back((int)(N[i] - '0'));
        }
    }
    REP(i, 3) {
        keta.push_back(0);
        val.push_back(0);
    }

    ll ans = 0;
    REP(i, n - 1) {  // 1~n-1 桁の数について
        if (K == 1) {
            ans += 9;
        } else if (K == 2) {
            ans += 9 * 9 * i;
        } else if (K == 3) {
            ans += 9 * 9 * 9 * (i * (i - 1) / 2);
        }
    }

    // n 桁の数について
    if (K == 1) {
        ans += val[0];  // 先頭は 1~val[0]通り
    } else if (K == 2) {
        ans += (val[0] - 1) * 9 * (n - 1);  // 先頭を 1~(val[0]-1) のどれかにする時
        ans += val[1];                      // 先頭を val[0] にして、2つ目を keta[1]+1 桁目で使う時
        ans += 9 * keta[1];  // 先頭を val[0] にして、2つ目を 1~keta[1] 桁目のどこかで使う時
    } else if (K == 3) {
        ans += (val[0] - 1) * 9 * 9 * (n - 1) * (n - 2) / 2;  // 先頭を 1~(val[0]-1) にする時
        ans += (val[1] - 1) * 9
               * (keta[1]);  // 先頭をval[0]にして、2つ目を keta[1]+1 桁目で1~(val[1]-1) のどれかにする時
        ans += val[2];  // 先頭をval[0]、2つ目を keta[1]+1 桁目で val[1] にして、3つ目を keta[2]+1 桁目で使う時
        ans += 9 * keta[2];  // 先頭をval[0]、2つ目を keta[1]+1 桁目で val[1] にして、3つ目を 1~keta[2]
                             // 桁目のどこかで使う時
        ans += 9 * 9 * (keta[1]) * ((keta[1]) - 1) / 2;  // 先頭をval[0]、2つ目を keta[2]+1 桁目で使う時
    }

    cout << ans << endl;
    return 0;
}
