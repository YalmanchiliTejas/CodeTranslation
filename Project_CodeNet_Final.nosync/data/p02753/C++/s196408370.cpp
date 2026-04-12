#include <bits/stdc++.h>
using namespace std;
// ----------------------R00TDADA------------------------------
#define rep(i, a, b) for (__typeof((b)) i = (a); i < (b); i++)
#define nrep(i, a, b) for (__typeof((b)) i = (a); i > (b); i--)
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define ppi pair<int, int>
#define pppi pair<ppi, int>
#define vi vector<int>
#define vii vector<ppi>
#define viii vector<pppi>
#define vs vector<string>
#define pb push_back
#define prq priority_queue
#define mp make_pair
#define mem(x, val) memset((x), (val), sizeof(x));
#define sz(x) (int)x.size()
#define M_PI 3.14159265358979323846
#define rootdada                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define M 1000000007
#define MAX 100005
const int N = 100005;
int fac[N];
int inv[N];

int power(int x, int p)
{
    if (p == 0)
        return 1;
    int y = power(x, p / 2);
    y *= y;
    y %= M;
    if (p % 2 == 0)
        return y;
    y *= x;
    y %= M;
    return y;
}

int nCr(int x, int y)
{
    int res = fac[x] * inv[y];
    res %= M;
    res *= inv[x - y];
    res %= M;
    return res;
}
int A[MAX], tree[4 * MAX];

bool prime[10000001];
void sieveFunction(int maxLimit)
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i <= maxLimit; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j < maxLimit; j += i)
                prime[j] = false;
        }
    }
}
vi primefactor;
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        primefactor.pb(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primefactor.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        primefactor.pb(n);
}
void build(int node, int start, int end)
{
    if (start == end)
        tree[node] = A[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        A[idx] = val;
        tree[node] += val;
    }
    else
    {
        int mid = (start - end) / 2 + end;
        if (start <= idx && idx <= mid)
        {
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}
//Longest Sum Contiguous Subarray (Kadane's Algorithm)
int maxSubArraySum(int a[], int start, int end)
{
    int max_so_far = 0, max_ending_here = 0;
    for (int i = start; i < end; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        else if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
int phi(int n)
{
    int result = n;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Breadth First Search Algorithm for a vector representation of a graph
// CALCULATE SHORTEST DISTANCE FROM STARTING VERTEX TO EVERY OTHER VERTEX

vector<int> adj[10001];
int dist[10001]; // distance array
int vis[10001];  //visited array
int par[10001];  //parent array

// src --> starting vertex

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    par[src] = -1;
    while (!q.empty())
    {
        int v = q.front();
        vis[v] = 1;
        q.pop();
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (vis[adj[v][i]] == 0)
            {
                q.push(adj[v][i]);
                vis[adj[v][i]] = 1;
                dist[adj[v][i]] = min(dist[adj[v][i]], dist[v] + 1);
                par[adj[v][i]] = v;

                // PRE-PROCESS THE CHILD OF THE CURRENT VERTEX
            }
        }
    }
}

void dfs(int src)
{
    vis[src] = 1;
    for (int i = 0; i < adj[src].size(); i++)
    {
        if (vis[adj[src][i]] == 0)
        {
            vis[adj[src][i]] = 1;
            dfs(adj[src][i]);
        }
    }
}

signed main()
{
    rootdada;

// fac[0] = 1;
// inv[0] = 1;
// for (int i = 1; i < N; i++)
// {
//     fac[i] = fac[i - 1] * i;
//     fac[i] %= M;
//     inv[i] = power(fac[i], M - 2);
// }

    string s;
    cin >> s;
    int l = s.length();
    int c = 0, d = 0;
    rep(i, 0, l)
    {
        if (s[i] == 'A')
            c++;
        else
        {
            d++;
        }
    }
    if (c == l || d == l)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
    }
}