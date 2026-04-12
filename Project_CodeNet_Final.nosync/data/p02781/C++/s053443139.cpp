#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 4;

ll dp[1010][2][1010];

void solve() {
    memset(dp,0,sizeof(dp));
    string A;
    int K;
    cin >> A >> K;

    const int n = A.size();

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= K; k++) {
                int x = j ? 9 : A[i] - '0';
                for (int d = 0; d <= x; d++) {
                    if(d == 0){
                        dp[i + 1][j || d < x][k] += dp[i][j][k];
                    }
                    else{
                        dp[i + 1][j || d < x][k + 1] += dp[i][j][k];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < 2; j++) {
        ans += dp[n][j][K];
    }
    cout << ans << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
