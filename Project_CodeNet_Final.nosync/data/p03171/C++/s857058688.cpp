#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int MOD = 1e9 + 7;
#define INF ((1<<30)-1)
#define LINF (1LL<<30)


ll dp[3100][3100];
int a[3100];
int main() {
    int N;
    cin >> N;
    rep(i,N) cin >> a[i];
    rep(i,N) dp[i][i] = 0;

    for(int len = 1; len <= N; len++) {
        for(int i = 0; i + len <= N; i++) {
            int j = i + len;

            if ((N-len)%2 == 0){
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }

            else{
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }

    }
    cout << dp[0][N] << endl;
}