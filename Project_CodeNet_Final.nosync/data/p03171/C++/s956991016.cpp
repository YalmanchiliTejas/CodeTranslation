#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

const int inf = 1e9 + 1;
const double eps = 1e-9;
const int MAXN = 3001;

int n;
int a[MAXN];
ll dp[MAXN][MAXN]; //dp[j][i] je (x-y) za interval od j do j+i

int main(){

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n-i; j++){
            if (i%2 == n%2) dp[j][i] = max(dp[j][i-1] + a[j+i-1], dp[j+1][i-1] + a[j]);
            else dp[j][i] = min(dp[j][i-1] - a[j+i-1], dp[j+1][i-1] - a[j]);
        }
    }

    cout << dp[0][n];

    return 0;

}