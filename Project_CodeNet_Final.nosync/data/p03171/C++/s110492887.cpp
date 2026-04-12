#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define em emplace
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i <= n; i++)
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
constexpr int INF = 1<<30;
constexpr ll LINF = 1LL<<58;
constexpr int mod = 1000000007;

ll dp[3030][3030];

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    if(n % 2 == 1){
        for (int i = 0; i < n; i++) dp[i][i] = A[i];
        for (int w = 1; w < n; w++) {
            for (int i = 0; i < n - w; i++) {
                if(w % 2 == 1) dp[i][i + w] = min(dp[i][i + w - 1] - A[i + w], dp[i + 1][i + w] - A[i]);
                else dp[i][i + w] =  max(dp[i][i + w - 1] + A[i + w], dp[i + 1][i + w] + A[i]);
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) dp[i][i] = -A[i];
        for (int w = 1; w < n; w++) {
            for (int i = 0; i < n - w; i++) {
                if(w % 2 == 1) dp[i][i + w] =  max(dp[i][i + w - 1] + A[i + w], dp[i + 1][i + w] + A[i]);
                else dp[i][i + w] = min(dp[i][i + w - 1] - A[i + w], dp[i + 1][i + w] - A[i]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}
