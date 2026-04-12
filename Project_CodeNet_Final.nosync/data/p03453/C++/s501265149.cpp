# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, m;
int s, t;

vector <pair <int, long long>> v[MAX_N];

long long d[2][MAX_N];
long long dp[2][MAX_N];

void calc (int id, int st)
{
    int i, x;
    long long dist;

    priority_queue <pair <long long, int>> pq;

    while (!pq.empty ())
        pq.pop ();

    for (i = 1; i <= n; i ++)
        d[id][i] = (1LL << 50);
    d[id][st] = 0;

    pq.push ({0, st});

    vector <int> ord;

    while (!pq.empty ())
    {
        pair <long long, int> crr = pq.top ();
        pq.pop ();

        dist = -crr.first;
        x = crr.second;

        if (d[id][x] < dist)
            continue;
        ord.push_back (x);

        for (i = 0; i < (int) v[x].size (); i ++)
        {
            if (d[id][v[x][i].first] > (dist + v[x][i].second))
            {
                d[id][v[x][i].first] = (dist + v[x][i].second);

                pq.push ({-d[id][v[x][i].first], v[x][i].first});
            }
        }
    }

    dp[id][st] = 1;


    for (int j = 0; j < (int) ord.size (); j ++)
    {
        x = ord[j];
        for (i = 0; i < (int) v[x].size (); i ++)
            if (d[id][x] + v[x][i].second == d[id][v[x][i].first])
            {
                dp[id][v[x][i].first] += dp[id][x];
                if (dp[id][v[x][i].first] >= MOD)
                    dp[id][v[x][i].first] -= MOD;
            }
    }

}

int main ()
{
    int i, p, q, c;

    scanf ("%d%d", &n, &m);
    scanf ("%d%d", &s, &t);

    for (i = 1; i <= m; i ++)
    {
        scanf ("%d%d%d", &p, &q, &c);
        v[p].push_back ({q, c});
        v[q].push_back ({p, c});
    }

    calc (0, s);
    calc (1, t);

    long long ans = (dp[0][t] * dp[0][t]) % MOD;

    for (i = 1; i <= n; i ++)
    {
        if ((d[0][i] * 2) == d[0][t] && (d[1][i] * 2) == d[0][t])
        {
            long long f = (long long) (dp[0][i] * dp[1][i]) % MOD;
            ans -= (f * f) % MOD;
            if (ans < 0)
                    ans += MOD;
        }

        for (int j = 0; j < (int) v[i].size (); j ++)
            if ((d[0][i] * 2) < d[0][t] && (d[1][v[i][j].first] * 2) < d[0][t] && (d[0][i] + d[1][v[i][j].first] + v[i][j].second) == d[0][t])
            {
                long long f = (long long) (dp[0][i] * dp[1][v[i][j].first]) % MOD;
                ans -= (f * f) % MOD;
                if (ans < 0)
                        ans += MOD;
            }
    }

    printf ("%lld\n", ans);

    return 0;
}
