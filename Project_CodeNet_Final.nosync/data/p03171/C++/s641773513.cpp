#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)
//
const int MX = 3002;
int dp[MX][MX]; // 1 - win, 0 - lose
int32_t main()
{
    // A =  { a_1 , a_ 2, ... a _ n}
    //
    int n;
    cin >> n;
    vector<int>a(n);
    forn(i,n)
    cin >> a[i];
    vector<int>pre(n + 1, 0);
    // правая не вкл
    pre[0]=0;
    for(int i = 1 ;i <= n; i++){
        pre[i]=pre[i-1]+a[i-1];
    }
    // .....a[i]
    // сколько набирает тот кто ходит
    for (int len = 1; len <= n; len++) {
        for(int l = 0; l < n; l++) {
            int r = l + len;
//            A  B
//            pre[r] - pre[l] - dp[l + 1][r]
//            dp[l + 1][r]
            dp[l][r] = max(dp[l][r], pre[r] - pre[l] - dp[l + 1][r]);
            dp[l][r] = max(dp[l][r], pre[r] - pre[l] - dp[l][r - 1]);
        }
    }
    cout << dp[0][n] - (pre[n] - dp[0][n]) << endl;
    return 0;
}