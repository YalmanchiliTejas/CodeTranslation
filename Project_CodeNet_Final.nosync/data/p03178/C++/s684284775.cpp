#include <bits/stdc++.h>

using namespace std;

string n;
vector<int> num;
long long dp[200005][2][100], k, d;
const long long oo = 1e9 + 7;

void get_num(string s, vector<int> &num)
{
    for (int i = 0; i < s.size(); i++)
    {
        num.push_back(s[i] - '0');
    }
}
long long calc(int idx, int tight, int mod) 
{
    if (idx == num.size())
        if (mod % k == 0)
            return 1;
        else
            return 0;
    if (dp[idx][tight][mod] != -1)
        return dp[idx][tight][mod];
    long long t = 0;
    int luu;
    if (tight == 1)
        luu = num[idx];
    else
        luu = 9;
    for (int i = 0; i <= luu; i++)
    {
        int new_tight = tight;
        if (tight == 1 && i < luu)
            new_tight = 0;
        t = (t + calc(idx + 1, new_tight, (i + mod) % k)) % oo;
    }
    dp[idx][tight][mod] = t % oo;
    return dp[idx][tight][mod] % oo;
}

long long solve(string s)
{
    num.clear();
    memset(dp, -1, sizeof(dp));
    get_num(n, num);
    return calc(0, 1, 0);
}

int main()
{
    cin >> n >> k;
    cout << ((solve(n) - 1)+oo) % oo;
}