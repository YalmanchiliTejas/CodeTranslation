#include <bits/stdc++.h>
#define llong long long

const llong mxn = 1e5 + 7;
const llong mod = 1e9 + 7;
const llong inf = 1e18 + 9;

using namespace std;

deque <llong> deq;
vector <llong> v;

llong n, a[mxn], k, dp[3001][3001], sum2, sum1;
bool ok = 0;

int main (){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }for (int i = 1; i <= n; i ++){
        for (int j = 1; j + i - 1 <= n; j ++){
            dp[i][j] = max(a[j] - dp[i - 1][j + 1], a[j + i - 1] - dp[i - 1][j]);
//            cout << dp[i][j] << ' ';
        }/*cout << endl;*/
    }
	cout << dp[n][1] << endl;
    return 0;
}