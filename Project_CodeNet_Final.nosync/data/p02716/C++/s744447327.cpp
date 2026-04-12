#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

ll dp[200005][4]; // dp[i][j] := i番目まで見てj個余分なXを入れたときのmax


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int k = 1 + n % 2;
    rep(i,n+1)rep(j,k+1)dp[i][j] = -1e15;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,k+1){
            // x を一個挿入する
            chmax(dp[i+1][j+1],dp[i][j]);

            // 余計なxを入れずにox列の通りに次の数を当てはめる
            ll now = dp[i][j]; // 現在までのmax
            if( (i+j)%2 == 0 ) now += a[i]; // 現在地がoだったら加算する
            chmax(dp[i+1][j],now); // i+1番目まで見てxをj個入れた時の値を更新する
        }
    }
    ll ans = dp[n][k];
    cout << ans << endl;
}