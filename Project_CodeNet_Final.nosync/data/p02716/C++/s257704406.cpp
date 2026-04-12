#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

void maxUpdate(lint& a, lint b) { a = max(a, b); }

int N;
lint A[200005];
lint dp[200005][10];

int main() {
    cin >> N;
    for_(i,0,N) cin >> A[i];
    A[N] = A[N+1] = 0;

    lint MIN_VAL = -1 * (1LL << 60);
    for_(i,0,N+4) for_(j,0,3) dp[i][j] = MIN_VAL;

    dp[0][0] = 0;
    for_(i,0,N) for_(j,0,3) {
        if (dp[i][j] == MIN_VAL) continue;
        maxUpdate(dp[i+2][j], dp[i][j] + A[i]);
        maxUpdate(dp[i+3][j+1], dp[i][j] + A[i+1]);
        maxUpdate(dp[i+4][j+2], dp[i][j] + A[i+2]);
    }

    lint ans = MIN_VAL;
    for_(i,N,N+4) {
        if (N & 1) maxUpdate(ans, max(dp[i][1], dp[i][2]));
        else maxUpdate(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << endl;
}