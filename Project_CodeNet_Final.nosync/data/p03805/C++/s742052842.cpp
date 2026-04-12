#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
const ll MOD = 1000000007;

const int nmax = 8;
bool graph[nmax][nmax];
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

ll mulMod(ll a, ll b)
{
    return (((a % MOD) * (b % MOD)) % MOD);
}

int dfs(int v,ll N,bool visited[nmax]){
    bool all_visited = true;

    for(int i = 0; i < N; i++)
    {
        if(!visited[i]){
            all_visited = false;
        }
    }

    if(all_visited){
        return  1;
    }
    int ret = 0;
    for(size_t i = 0; i < N; i++)
    {
        if(!graph[v][i]){
            continue;
        }
        if(visited[i]){
            continue;
        }

        visited[i] = true;
        ret += dfs(i,N,visited);
        visited[i] = false;
    }

    return ret;

}

int main()
{
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    for (int i = 0; i < M; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = true;
        graph[b - 1][a - 1] = true;
    }
    bool visit[nmax];
    visit[0] = true;
    int ans = dfs(0, N, visit);
    cout << ans << endl;
    return 0;
}
