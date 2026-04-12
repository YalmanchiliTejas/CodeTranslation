#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;
template <typename T>
void vecin(vector<T> &v, int n = 0)
{
    if (n == 0)
        n = v.size();
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
}
template <typename T>
void vecout(vector<T> &v, int n = 0)
{
    if (n == 0)
        n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        cout << v[i] << " ";
    }
    cout << v[n - 1] << endl;
}

vector<ll> barlen(55), pnum(55);

ll dfs(int hier, ll layer){
    if (hier == 0){
        return 1;
    }
    if (layer == 1){
        return 0;
    }else if (layer > 1 && layer <= 1 + barlen[hier-1]){
        return dfs(hier - 1, layer - 1);
    }else if (layer == 2 +barlen[hier-1]){
        return 1 + pnum[hier - 1];
    }
    else if (layer > 2 + barlen[hier - 1] && layer <= 2 + 2*barlen[hier - 1])
    {
        return 1 + pnum[hier - 1] + dfs(hier - 1, layer - 2 - barlen[hier - 1]);
    }else{
        return 1 + 2 * pnum[hier - 1];
    }
}

int main()
{
    ciosup;
    int n;
    ll x;
    cin >> n >> x;
    barlen[0] = 1;
    pnum[0] = 1;
    FOR(i, 1, n+1)
    {
        barlen[i] = barlen[i - 1] * 2 + 3;
        pnum[i] = pnum[i - 1] * 2 + 1;
    }
    cout << dfs(n, x) << endl;
}