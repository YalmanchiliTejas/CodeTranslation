#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string N;
int K;

ll dp[101][2][5];

ll solve(int pos = 0, bool tight = true, int ck = 0)
{
    if (ck > K) {
        return 0;
    }
    if (pos == N.size()) {
        return ck == K ? 1 : 0;
    }

    int digit = N[pos] - '0';

    ll& rdp = dp[pos][tight][ck];
    if (~rdp) return rdp;

    ll res = 0;
 
    for (int i = 0; i <= (tight ? digit : 9); i++) {
        res += solve(pos+1, tight && digit == i, i==0 ? ck : ck + 1);
    }

    return rdp = res;
}

int main()
{
    cin >> N>>K;
    memset(dp, -1, sizeof(dp));

    cout << solve() <<endl;
}
