#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
using namespace std;
ll n, a[3030], Dp[3030][3030];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    
    for (int i=n; i>0; i--)
        for (int j = i; j<=n; j++)
            Dp[i][j] = max(a[i] - Dp[i+1][j], a[j] - Dp[i][j-1]);

    cout << Dp[1][n] << '\n';
    return 0;
}
