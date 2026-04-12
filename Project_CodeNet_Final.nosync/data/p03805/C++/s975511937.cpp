#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define pi pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mp make_pair
#define pb push_back
#define fall(i, a, b) for (int i = a; i < b; i++)
#define sz(x) (ll) x.size()
#define all(x) x.begin(), x.end()
#define ed cout << "ed";
#define time_passed 1.0 * clock() / CLOCKS_PER_SEC
ll MOD = 1e9 + 7;
ll MOD1 = 1e9 + 123;
ll MOD2 = 1e9 + 321;
vector<int> G[100];
vector<int> vis(100, 0);
int F, N;
void dfs(int y, unordered_map<int, int> mp)
{
    // cout<<y<<endl ;
    mp[y]++;
    // for(auto h : mp)
    // cout<<h.ff<<" "<<h.ss<<endl;
    // cout<<endl;
    for (auto h : G[y])
    {
        if (mp.size() == N)
        {
            F++;
            return;
        }
        if (mp.find(h) == mp.end())
        {
             dfs(h, mp);
        }
    }
}
int main()
{
    fio;
    ll t, a, n, q, k, i, l, m, c, u, f, j, p, x, y, b, d;
    cin >> n >> m;
    N = n;
    for (i = 0; i < m; i++)
        cin >> a >> b, G[a].pb(b), G[b].pb(a);
    unordered_map<int, int> mp;
    dfs(1, mp);
    cout << F << endl;

    return 0;
}
