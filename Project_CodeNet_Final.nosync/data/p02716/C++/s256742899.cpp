#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ff first
#define ss second
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const ll INF = 1e18 + 5;
int get_jj(int i, int j){
    int x = (i / 2) - 3;
    return j - x;
}
int main() {
    IO;
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a)
        cin >> x;
    // dp[i][j][k] -> maximum sum when chose j elements from first i elements, and no two elements are adjacent
    //                  k says, if last element was taken or not
    vector<vector<vector<ll> > > dp(n, vector<vector<ll> >(5, vector<ll>(2, -INF)));;
    dp[0][get_jj(0, 0)][0] = 0;
    dp[0][get_jj(0, 1)][1] = a[0];
    for(int i = 0; i < n - 1; i++){
        for(int j = (i / 2) - 3; j <= (i / 2) + 1 && j <= (i + 1); j++){
            if(j < 0) continue;

            for(int k = 0; k < 2; k++) {
                if (dp[i][get_jj(i, j)][k] == -INF) continue;
                if (k == 1) {
                    if(get_jj(i + 1, j) >= 0 && get_jj(i + 1, j) < 5)
                        dp[i + 1][get_jj(i + 1, j)][1 - k] = max(dp[i + 1][get_jj(i + 1, j)][1 - k], dp[i][get_jj(i, j)][k]);
//                    cout << i << ' ' << j << ' ' << k << " -> " << i + 1 << ' ' << j << ' ' << 1 - k << '\n';
                }
                else{
                    if(get_jj(i + 1, j + 1) >= 0 && get_jj(i + 1, j + 1) < 5)
                        dp[i + 1][get_jj(i + 1, j + 1)][1 - k] = max(dp[i + 1][get_jj(i + 1, j + 1)][1 - k], dp[i][get_jj(i, j)][k] + a[i + 1]);
                    if(get_jj(i + 1, j) >= 0 && get_jj(i + 1, j) < 5)
                        dp[i + 1][get_jj(i + 1, j)][k] = max(dp[i + 1][get_jj(i + 1, j)][k], dp[i][get_jj(i, j)][k]);

//                    cout << i << ' ' << j << ' ' << k << " -> " << i + 1 << ' ' << j + 1 << ' ' << 1 - k << " And " << i + 1 << ' ' << j << ' ' << k << '\n';
                }
            }
        }
    }

//    int x = 0;
//    jj = (n - 1) / 2 - 1;
//    x += (n / 2) - jj;
    cout << max(dp[n - 1][get_jj(n - 1, n / 2)][0], dp[n - 1][get_jj(n - 1, n / 2)][1]) << '\n';
    return 0;
}
