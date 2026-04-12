#include <bits/stdc++.h>

using namespace std;

const int N = 105;
long long memo[N][2][4];
string s;

long long solve (int i , bool less , int rem) {
    if (rem == 0)
        return 1;

    if (i == s.size())
        return 0;

    long long &ret = memo[i][less][rem];
    if (~ret)
        return ret;

    ret = 0;

    int r = less ? 9 : s[i];
    for (int d = 0 ; d <= r ; d++)
        ret += solve(i + 1 , less || (d < s[i] ), rem - (d != 0));

    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int k;
    cin >> s >> k;

    for (char &c : s)
        c -= '0';

    memset(memo , -1 , sizeof memo);
    cout << solve(0 , 0 , k);
}
