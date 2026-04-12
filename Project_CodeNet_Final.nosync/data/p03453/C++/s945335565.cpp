#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pair;
typedef pair< ll, int > pli;
const int Nmax = 2e5 + 5, Mod = 1e9 + 7;

vector<int> wA, wB;
vector< ll > dA, dB;

int i, n, x, y, dist, A, B, m;
vector< Pair > v[Nmax];
priority_queue < pli, vector< pli >, greater < pli > > heap;
pair < Pair, int > edge[Nmax];
bool inQueue[Nmax];

void dijk(int node, vector<ll> &d, vector<int> &ways)
{
    d.resize(n+2); ways.resize(n+2);
    for(i=1; i<=n; ++i) d[i] = LLONG_MAX / 4, inQueue[i] = 0, ways[i] = 0;

    d[node] = 0;
    ways[node] = 1;
    heap.push({0, node});
    inQueue[node] = 1;

    while(heap.size())
    {
        node = heap.top().second;
        inQueue[node] = 0;
        heap.pop();

        for(auto e : v[node])
        {
            int to = e.first;
            if(d[to] > d[node] + e.second)
            {
                d[to] = d[node] + e.second;
                if(!inQueue[to]) heap.push({ d[to], to }), inQueue[to] = 1;
            }
        }
    }

    for(i=1; i<=n; ++i) heap.push({ d[i], i });

    while(heap.size())
    {
        node = heap.top().second;
        heap.pop();

        for(auto e : v[node])
            if(d[e.first] == d[node] + e.second)
                ways[e.first] = (ways[e.first] + ways[node]) % Mod;
    }
}

int sq(int x)
{
    return (ll) x * x % Mod;
}

int main()
{
    cin.sync_with_stdio(false);

    cin >> n >> m >> A >> B;
    for(i=1; i<=m; ++i)
    {
        cin >> x >> y >> dist;
        v[x].push_back({y, dist});
        v[y].push_back({x, dist});
        edge[i] = { {x, y}, dist };
    }

    dijk(A, dA, wA);
    dijk(B, dB, wB);

    ll ans = sq(wA[B]);

    for(i=1; i<=n; ++i)
        if(i != A && i != B)
            if(dA[i] + dB[i] == dA[B] && dA[i] == dB[i])
            {
                ans -= sq( (ll) wA[i] * wB[i] % Mod);
                if(ans < 0) ans += Mod;
            }

    for(i=1; i<=m; ++i)
    {
        x = edge[i].first.first;
        y = edge[i].first.second;
        dist = edge[i].second;

        if(dA[x] + dist + dB[y] == dA[B])
        {
            ll start1 = dA[x], finish1 = dA[x] + dist, start2 = dB[y], finish2 = dB[y] + dist;

            if(!(finish1 <= start2 || finish2 <= start1))
            {
                ans -= sq( (ll) wA[x] * wB[y] % Mod );
                if(ans < 0) ans += Mod;
            }
        }

        swap(x, y);

        if(dA[x] + dist + dB[y] == dA[B])
        {
            ll start1 = dA[x], finish1 = dA[x] + dist, start2 = dB[y], finish2 = dB[y] + dist;

            if(!(finish1 <= start2 || finish2 <= start1))
            {
                ans -= sq( (ll) wA[x] * wB[y] % Mod );
                if(ans < 0) ans += Mod;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
