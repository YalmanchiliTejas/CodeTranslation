#include <bits/stdc++.h>

#define MAX_N 100000
#define MAX_M 200000

#define MOD 1000000007

#define xx first
#define yy second

using namespace std;

typedef long long lint;

const lint sqrInf = 1LL * (1e18) + 1;

lint dp[MAX_N + 1][2];
lint t[MAX_N + 1][2];

bool viz[MAX_N + 1];

int n, m;
int st, dr;
lint rez;

priority_queue <pair<lint, int>, vector<pair<lint, int>>, std::greater <pair<lint, int>>> p;

struct edge
{
    int a, b, c;
};

edge edg[MAX_M + 1];

inline void inm(lint &a, lint b)
{
    a = a * b;

    if(a >= MOD)
        a %= MOD;
}

inline void add(lint &a, lint b)
{
    a += b;

    if(a >= MOD)
        a -= MOD;
}

inline void sub(lint &a, lint b)
{
    a -= b;

    if(a < 0)
        a += MOD;
}

vector <pair<int, int>> g[MAX_N + 1];

void add(int a, int b, int c)
{
    g[a].push_back({b, c});
}

void readFile()
{
    cin >> n >> m;
    cin >> st >> dr;

    int i;
    int a, b, c;
    for(i = 1; i <= m; i ++)
    {
        cin >> a >> b >> c;
        edg[i] = {a, b, c};

        add(a, b, c);
        add(b, a, c);
    }
}

void drum(int start, int cr)
{
    memset(viz, 0, sizeof(viz));
    while(p.size() > 0)
        p.pop();

    for(int i = 1; i <= n; i ++)
        t[i][cr] = sqrInf;

    t[start][cr] = 0;
    dp[start][cr] = 1;
    p.push({0, start});
    while(p.size() > 0)
    {
        int mn = p.top().yy;
        p.pop();
        if(viz[mn] == 0)
        {
            viz[mn] = 1;

            for(auto u : g[mn])
            {
                if(t[u.xx][cr] > t[mn][cr] + u.yy)
                {
                    t[u.xx][cr] = t[mn][cr] + u.yy;
                    dp[u.xx][cr] = 0;
                    p.push({t[u.xx][cr], u.xx});
                }

                if(t[u.xx][cr] == t[mn][cr] + u.yy)
                    add(dp[u.xx][cr], dp[mn][cr]);
            }
        }
    }
}

void solve()
{
    drum(st, 0);
    drum(dr, 1);

    rez = dp[dr][0];
    inm(rez, dp[dr][0]);

   // cout << t[dr][0] << " " << t[st][1] << "\n";
   // cout << dp[dr][0] << " " << dp[st][1] << "\n";

    //cout << rez << "\n";

    int i;
    lint mn = t[dr][0];
    for(i = 1; i <= n; i ++)
    {
        if(t[i][0] == t[i][1] && t[i][0] + t[i][1] == mn)
        {
            lint pos = dp[i][0];
            inm(pos, dp[i][1]);
            inm(pos, pos);
            sub(rez, pos);
        }
    }

    for(i = 1; i <= m; i ++)
    {
        int a = edg[i].a;
        int b = edg[i].b;
        int c = edg[i].c;

       // cout << t[a][1] << " " << t[b][0] << " ++ " << c << "\n";
        if(t[a][0] + t[b][1] + c == mn && 1.0D * t[a][0] + c > (1.0D * mn / 2.0D) && 1.0D * t[b][1] + c > (1.0D * mn / 2.0D) && 1.0D * t[a][0] < (1.0D * mn / 2.0D) && t[b][1] < (1.0D * mn / 2.0D))
        {
           // cout << "SACDE " << a << " " << b << " " << t[a][0] << " " << t[b][1] << "\n";

            lint pos = dp[a][0];
            inm(pos, dp[b][1]);
            inm(pos, pos);
            sub(rez, pos);
        }

        else
            if(t[a][1] + t[b][0] + c == mn && 1.0D * t[a][1] + c > (1.0D * mn / 2.0D) && 1.0D * t[b][0] + c > (1.0D * mn / 2.0D) && 1.0D * t[a][1] < (1.0D * mn / 2.0D) && t[b][0] < (1.0D * mn / 2.0D))
            {
                //cout << "SACDE " << a << " " << b << " " << t[a][1] << " " << t[b][0] << "\n";

                lint pos = dp[a][1];
                inm(pos, dp[b][0]);
                inm(pos, pos);
                sub(rez, pos);
            }
    }
}

void printFile()
{
    cout << rez << "\n";
}

int main()
{
    readFile();

    solve();

    printFile();

    return 0;
}
