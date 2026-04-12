#include <bits/stdc++.h>

#define NMAX 3005
using namespace std;

long long v[NMAX], dp[NMAX][NMAX];

long long solve(int st, int dr){
    if(st > dr)
        return 0;
    if(st == dr)
        return v[st];
    if(dp[st][dr] != -1)
        return dp[st][dr];
    long long rez = v[st] - solve(st + 1, dr);
    rez = max(rez, v[dr] - solve(st, dr - 1));
    dp[st][dr] = rez;
    return dp[st][dr];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] = -1;

    cout << solve(1, n) << '\n';
    return 0;
}
