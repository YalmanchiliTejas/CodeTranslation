#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define INF 0x3f3f3f3f 
#define MEM(x,y) memset(x,y,sizeof(x))
#define int long long
#define rep(i , a , b) for(int i = a ; i <= b ; i ++)
#define P pair<int,int>
#define  sc(a) scanf("%lld",&a)
#define pf(a) printf("%lld ",a)
using namespace std;
#define int long long
const int N = 1005;
char s[1005];
int a[1005];
int n, k, ans;
int dp[1005][5];
signed main() {
    cin >> s+ 1;
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) a[i] = s[i]-'0';
    cin >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= 3; j++) {
            dp[i][j] = dp[i - 1][j] + 9 * dp[i - 1][j - 1];
        }
    }
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            if (k - temp >= 0) ans += dp[n - i][k - temp];
            if (k - temp - 1 >= 0) ans += (a[i] - 1) * dp[n - i][k - temp - 1];
            temp++;
        }
      
    }
    if (temp == k) ++ans;
    cout << ans;
}