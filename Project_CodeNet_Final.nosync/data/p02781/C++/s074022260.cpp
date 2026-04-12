#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int dp[102][2][5];

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    string N;
    cin >> N;
    int K;
    cin >> K;

    int lenN = (int)N.size();

    dp[0][0][0] = 1;
    for (int i = 0; i < lenN; i++) {
        int Ni = N[i] - '0';
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j <= K; j++) {
                for (int d = 0; d <= (smaller ? 9 : Ni); d++) {
                    dp[i + 1][smaller || (d < Ni)][j + (d != 0)] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[lenN][0][K] + dp[lenN][1][K] << endl;

    return 0;
}