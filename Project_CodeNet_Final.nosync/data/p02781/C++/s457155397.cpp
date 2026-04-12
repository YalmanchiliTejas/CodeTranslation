#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

string n;
int k;
int dp[100][4][2];

int f(int i, int r, int s)
{
    if (r > k)
        return 0;
    if (i == n.size())
        return r == k;
    int& sol = dp[i][r][s];
    if (sol != -1)
        return sol;

    sol = 0;
    int d = n[i] - '0';
    for (int j = 0; j <= 9; ++j)
    {
        if (s == 0 && j > d)
            continue;
        sol += f(i + 1, r + (j != 0 ? 1 : 0), (j < d ? 1 : s));
    }
    return sol;
}

int main()
{
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, 0);
}
