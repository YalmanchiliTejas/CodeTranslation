#include<bits/stdc++.h>

using namespace std;

int N, M, S, T, ways[2][100009], x[200009], y[200009], z[200009];
long long dist[2][100009];
const int mod = 1e9 + 7;
vector < pair < int, int > > v[100009];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

priority_queue < pair < long long, int > > PQ;
void dijkstra (int lin, int source)
{
    for (int i=1; i<=N; i++)
        dist[lin][i] = -1;
    dist[lin][source] = 0, PQ.push ({0, source}), ways[lin][source] = 1;
    while (!PQ.empty ())
    {
        pair < long long, int > curr = PQ.top ();
        PQ.pop ();
        if (dist[lin][curr.second] != -curr.first) continue;
        int nod = curr.second;
        long long d = dist[lin][nod];
        for (auto it : v[nod])
            if (dist[lin][it.first] + it.second == d)
                adto (ways[lin][nod], ways[lin][it.first]);
        for (auto it : v[nod])
            if (dist[lin][it.first] == -1 || dist[lin][it.first] > d + it.second)
                dist[lin][it.first] = d + it.second, PQ.push ({-dist[lin][it.first], it.first});
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
scanf ("%d %d", &S, &T);
for (int i=1; i<=M; i++)
    scanf ("%d %d %d", &x[i], &y[i], &z[i]), v[x[i]].push_back ({y[i], z[i]}), v[y[i]].push_back ({x[i], z[i]});
dijkstra (0, S);
dijkstra (1, T);
long long minT = dist[0][T];
assert (dist[0][T] == dist[1][S] && ways[0][T] == ways[1][S]);
int ans = mul (ways[0][T], ways[0][T]);
for (int i=1; i<=N; i++)
    if (2LL * dist[0][i] == minT && dist[0][i] + dist[1][i] == minT)
    {
        int paths = mul (ways[0][i], ways[1][i]);
        ans = subtract (ans, mul (paths, paths));
    }
for (int i=1; i<=M; i++)
    for (int t = 0; t < 2; t ++, swap (x[i], y[i]))
        if (2 * dist[0][x[i]] < minT && minT < 2LL * (dist[0][x[i]] + z[i]) && dist[0][x[i]] + dist[1][y[i]] + z[i] == minT)
        {
            int paths = mul (ways[0][x[i]], ways[1][y[i]]);
            ans = subtract (ans, mul (paths, paths));
        }
printf ("%d\n", ans);
return 0;
}
