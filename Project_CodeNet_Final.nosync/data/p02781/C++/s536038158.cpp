#include<bits/stdc++.h>
#define GO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
const int Max = 2e3 + 5;
const int Mod = 1e9 + 7;

int n, k;
string s;
ll dp[Max][Max][2];

ll Try(int i, int j, bool b)
{
    if (j > k)
        return 0;
    if (i == n)
        return j == k;
    ll& ret = dp[i][j][b];
    if (ret + 1)
        return ret;
    ret = 0;
    int u = (b ? 9 : s[i] - '0');
    for (int l = 0; l <= u; l++)
        ret += Try(i + 1, j + (l > 0), b || l < s[i] - '0');
    return ret;
}

int main()
{
    GO;
    cin >> s;
    n = s.size();
    cin >> k;
    memset(dp, -1, sizeof(dp));
    cout << Try(0, 0, 0);
    return 0;
}