#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5, mod = 1e9 + 7;

string s;
int d, n, f[maxn][100][2];

int dp(int i, int j, int less)
{
    if (i == n+1) return (j == 0);
    if (f[i][j][less] != -1) return f[i][j][less];
    int &res = f[i][j][less]; res = 0;
    int x = 9;
    if (!less) x = s[i] - '0';
    for(int k=0; k<=x; ++k) 
        res = (res + dp(i + 1, (j + k) % d, (k < x) || less)) % mod;
    return res;
}

int main()
{
    #ifdef NTMA 
        freopen("abc.inp", "r", stdin);
    #endif
    memset(f, 255, sizeof(f));
    cin >> s >> d;
    n = s.size();
    s = ' ' + s;
    cout << (dp(1, 0, 0) - 1 + mod) % mod;
    return 0;
}