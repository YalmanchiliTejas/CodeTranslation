#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
const int MAXN = 3001;
long long a[MAXN];
long long dp[MAXN][MAXN];

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j ++) dp[i][j] = 0;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for(int j = 1; j <= N; j++) for(int i = j-1; i >= 1; i--) dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    cout << dp[1][N];
}