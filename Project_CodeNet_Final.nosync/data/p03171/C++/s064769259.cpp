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

using namespace std;

int n;
const int maxn = 3005;

int a[maxn];

typedef long long LL;

LL dp[maxn][maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i++){
        dp[i][i - 1] = 0;
    }
    for(int len = 1;len <= n;len++){
        for(int i = 1;i + len - 1 <= n;i++){
            int j = i + len - 1;
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]); 
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
