#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

constexpr ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    int k;
    cin >> n >> k;

    ll dp[110][2][2][5]; //idx,started?,same?,not0
    memset(dp, 0, sizeof(dp));

    dp[0][0][0][0] = 1;
    dp[0][1][1][1] = 1;
    if (n[0] > '1')
        dp[0][true][false][1] = n[0] - '1';

    for (int i = 1; i < n.size(); i++)
    {
        dp[i][false][false][0] = 1;

        for (int s = 1; s <= k; s++)
        {
            if (s == 1)
            {
                dp[i][true][false][s] += dp[i - 1][false][false][0] * 9;
            }
            else
            {
                if (n[i] > '0')
                    dp[i][true][true][s] += dp[i - 1][true][true][s - 1];
                if (n[i] > '1')
                {
                    dp[i][true][false][s] += dp[i - 1][true][true][s - 1] * (n[i] - '1');
                }
                dp[i][true][false][s] += dp[i - 1][true][false][s - 1] * 9;
            }

            if (n[i] == '0')
                dp[i][true][true][s] += dp[i - 1][true][true][s];
            else
                dp[i][true][false][s] += dp[i - 1][true][true][s];

            dp[i][true][false][s] += dp[i - 1][true][false][s];
        }
    }

    ll res = 0;
    for (int i = 0; i < 2; i++)
        res += dp[n.size() - 1][true][i][k];

    cout << res << endl;

    return 0;
}
