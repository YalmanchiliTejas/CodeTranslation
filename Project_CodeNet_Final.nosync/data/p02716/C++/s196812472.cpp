#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - 1e8;
const ll INFLL = numeric_limits<ll>::max() - 1e17;

signed main() {
    int N;
    cin >> N;
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(3, -INFLL)));
    dp[0][1][0] = 0;
    for (int i = 0; i < N; i++) {
        ll A;
        cin >> A;
        for (int j = 0; j <= 1; j++) for (int k = 0; k <= 2; k++) {
            if (j + k < 3) dp[i + 1][1][j + k] = max(dp[i + 1][1][j + k], dp[i][j][k]);
            if (j == 1) dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][j][k] + A);
        }
    }
    if (N % 2 == 0) cout << max(dp[N][1][0], dp[N][0][1]) << endl;
    else cout << max(dp[N][0][2], dp[N][1][1]) << endl;
}
