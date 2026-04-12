#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
        return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
        int n;
        cin >> n;

        vector<int> a(n);
        rep (i, n) cin >> a[i];

        // dp[i][j][k] := i番目について、jは選んだ、kは今までに飛ばした数
        auto dp = make_v(n + 10, 2, 3, numeric_limits<ll>::min() / 2);
        dp[0][0][0] = 0;

        rep (i, n) {
                rep (j, 2) rep (k, 3) {
                        dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][1][k]);
                        dp[i + 1][1][k] = max(dp[i + 1][1][k], dp[i][0][k] + a[i]);
                }

                rep (k, 2) {
                        dp[i + 1][0][k + 1] = max(dp[i + 1][0][k + 1], dp[i][0][k]);
                }
        }

        if (n % 2 == 0) {
                cout << max(dp[n][0][0], dp[n][1][1]) << endl;
        } else {
                cout << max(dp[n][0][1], dp[n][1][2]) << endl;
        }

        return 0;
}
