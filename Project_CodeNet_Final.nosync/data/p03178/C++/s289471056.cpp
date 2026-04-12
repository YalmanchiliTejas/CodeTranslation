#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define db(...) #__VA_ARGS__ << ": " << __VA_ARGS__
using ii=long long;
const int M = 1e9 + 7;
string s;
int MOD;
int pd[1 << 15][2][101];
ii dp[1 << 15][2][101];
ii calc(int x, int f, int m)
{
    if (x == s.size()) return m == 0;
    if (pd[x][f][m]) return dp[x][f][m];
    pd[x][f][m] = 1;
    ii r = 0;
    for (int j = 0; j <= (f ? 9 : s[x]); ++j) {
        r += calc(x + 1, f || (j < s[x]), (m + j) % MOD);
        r %= M;
    }
    return dp[x][f][m] = r;
}
int main()
{
    cin >> s >> MOD;
    for (char &c : s) c -= '0';
    cout << (calc(0, 0, 0) - 1 + M) % M << "\n";;
}
