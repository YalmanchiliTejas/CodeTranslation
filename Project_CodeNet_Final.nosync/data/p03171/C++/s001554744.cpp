#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define openfiles ifstream cin("input.txt"); ofstream cout("output.txt");

using namespace std;

ll a[5000], dp[5000][5000][2];

ll solve(int l, int r, int hod)
{
    if(l == r)
        return a[l];
    if(!dp[l][r][hod])
        return dp[l][r][hod] = max(-solve(l + 1, r, 1 - hod) + a[l], -solve(l, r - 1, 1 - hod) + a[r]);
    return dp[l][r][hod];
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1, 0);
}
//10 20 30 40
//30 50 70
//90 140
