#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

const ll INF = 1LL << 60;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    int rest = N - N / 2 - N / 2 + 1;
    vector<vector<ll>> dp(N, vector<ll>(rest + 1, -INF));
    rep(i, 0, rest + 1) {
        dp[i][rest - i] = A[i];
    }
    rep(i, 0, N) rep(j, 0, rest + 1) {
        rep(k, 0, j + 1) {
            if (i + k + 2 >= N) {
                break;
            }
            chmax(dp[i + k + 2][j - k], dp[i][j] + A[i + k + 2]);
        }
    }
    ll ans = -INF;
    rep(i, 0, rest + 1) {
        chmax(ans, dp[N - 1 - i][i]);
    }
    cout << ans << endl;
    return 0;
}