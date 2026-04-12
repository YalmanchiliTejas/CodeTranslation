#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int d;
int dp[10010][110][2][2];
int md = 1e9+7;
void addMd(int &x, int y)
{
    x += y;
    if (x >= md) x -= md;
}
int f(int idx, int rem, bool smaller, bool taken)
{
    if (idx == s.size()) return !rem;
    int &ret = dp[idx][rem][smaller][taken];
    if (~ret) return ret;
    ret = 0;
    for (int j = 0; j <= 9; ++j)
    {
        if (idx == s.size()-1 && !j && !taken) continue;
        if (smaller)
//            addMd(ret, f(idx+1, (rem*10+j)%d, smaller, taken || j));
            addMd(ret, f(idx+1, (rem+j)%d, smaller, taken || j));
        else if (j == s[idx] - '0')
//            addMd(ret, f(idx+1, (rem*10+j)%d, 0, taken || j));
            addMd(ret, f(idx+1, (rem+j)%d, 0, taken || j));
        else if (j < s[idx] - '0')
//            addMd(ret, f(idx+1, (rem*10+j)%d, 1, taken || j));
            addMd(ret, f(idx+1, (rem+j)%d, 1, taken || j));
    }

    return ret;
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> s >> d;
    cout << f(0, 0, 0, 0);

    return 0;
}
