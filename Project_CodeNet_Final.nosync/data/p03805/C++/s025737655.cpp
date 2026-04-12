#include <bits/stdc++.h>
using namespace std;

int N, M;
int link[10][10];
int dp[1 << 10][10];
int main() {
    cin >> N >> M;
    memset(link, 0, sizeof(link));
    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        link[a][b] = 1;
        link[b][a] = 1;
    }

    dp[1][0] = 1;
    for(int bit=1; bit<(1<<N); bit++) {
        for(int i=0; i<N; i++) {
            if(dp[bit][i] == 0) continue;
            for(int j=0; j<N; j++) {
                if(bit >> j & 1) continue;
                if(!link[i][j]) continue;
                int nbit = bit | (1 << j);
                dp[nbit][j] += dp[bit][i];
            }
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++) {
        ans += dp[(1<<N)-1][i];
    }
    cout << ans << endl;
}