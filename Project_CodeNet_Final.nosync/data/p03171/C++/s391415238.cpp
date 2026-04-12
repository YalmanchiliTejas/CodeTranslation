#include <bits/stdc++.h>

#define MAXN 3001

using namespace std;

typedef long long ll;

ll data[MAXN];
ll dp[MAXN][MAXN];

ll Solve(int a, int b, ll acum){
    if(dp[a][b] == 0) {
        if (a == b)
            dp[a][b] = data[a];
        else {
            Solve(a + 1, b, acum - data[a]);
            Solve(a, b - 1, acum - data[b]);
            dp[a][b] = acum - min(dp[a + 1][b], dp[a][b - 1]);
        }
    }
    return dp[a][b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll acum = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> data[i];
        acum += data[i];
    }

    ll best = Solve(1, n, acum);
    cout << 2 * best - acum << "\n";

    return 0;
}//RUL0