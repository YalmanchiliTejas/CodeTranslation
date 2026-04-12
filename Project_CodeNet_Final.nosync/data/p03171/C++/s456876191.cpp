#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int a[3005];

LL dp[3005][3005][2];
bool done[3005][3005][2];

LL solve(int st, int dr, int who)
{
    if(st > dr) return 0;
    if(done[st][dr][who])   return dp[st][dr][who];
    done[st][dr][who] = 1;

    LL ans = 0;
    if(who == 1)
        ans = max( a[st] + solve(st + 1, dr, 0), a[dr] + solve(st, dr - 1, 0) );
    else
        ans = min( -a[st] + solve(st + 1, dr, 1), -a[dr] + solve(st, dr - 1, 1) );
    dp[st][dr][who] = ans;
    return ans;
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];

    LL ans = solve(1, N, 1);
    cout << ans << '\n';
}