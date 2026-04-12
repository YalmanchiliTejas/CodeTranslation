#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>

#define MAXN 3005
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

ll arr[MAXN];
ll dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(dp, 0LL, sizeof(dp));
    
    for(int i = n; i > 0; i--) {
        for(int j = i; j <= n; j++) {
            if(i == j) dp[i][i] = arr[i];
            else dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << '\n';

    return 0;
}