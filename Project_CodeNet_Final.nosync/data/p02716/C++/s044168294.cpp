#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200200;
const ll Inf = 1e18;

int n;
int a[N];
ll Dp[N][3];

ll Rec(int i, int j)
{
    if(j < 0)   return -Inf;
    if(i >= n)  return j <= 1 ? 0 : -Inf;

    if(Dp[i][j] + 1)    return Dp[i][j];

    return Dp[i][j] = max(a[i] + Rec(i + 2, j), Rec(i + 1, j - 1));
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)  scanf("%d", a + i);

    memset(Dp, -1, sizeof(Dp));

    cout << Rec(0, n & 1 ? 2 : 1) << endl;
}
