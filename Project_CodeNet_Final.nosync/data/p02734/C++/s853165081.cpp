#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

const int mod = 998244353;

const int maxn = 3005;

int dp[maxn][maxn];

void add(int &a, int b){
    a += b;
    if(a > mod)
        a -= mod;
}

int n, s, a[maxn];

int main(){
    cin >> n >> s;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < s;j++){
            dp[i][j] = dp[i - 1][j];
        }
        add(dp[i][a[i]], i);
        for(int j = a[i] + 1;j <= s;j++){
            add(dp[i][j], dp[i - 1][j - a[i]]);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        //cout << dp[i][s] << endl;
        add(ans, 1LL * dp[i][s] * (n + 1 - i) % mod);
    }
    cout << ans << endl;
    return 0;
}
