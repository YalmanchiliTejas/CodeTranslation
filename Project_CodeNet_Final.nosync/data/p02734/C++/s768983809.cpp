#include <bits/stdc++.h>

using namespace std;
long long mod = 998244353;
long long dp[3030][3030][3];
int main()
{

int n,s;
cin >> n >> s;
vector <int> a(n);
for (int i=0; i<n; i++) cin >> a[i];



dp[0][0][0] = 1;
for (int i=0; i<n; i++)
        for (int j=0; j<=s; j++)
{
    (dp[i+1][j][0]+=dp[i][j][0]) %=mod;
    (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %=mod;
    (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1]+ dp[i][j][2]) %=mod;
    if (j+a[i]<=s)
        {
            (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %=mod;
            (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %=mod;
        }
}

cout << dp[n][s][2];
}

/*
dp[i][s][t] = The number of combinations chosen from the first i elements, such that the sum of elements is s and
L has not been added to the tuple yet (When t = 0)
L has been added but R has not been added yet(When t = 1)
both L and R has been added to the tuple(When t = 2)

*/






