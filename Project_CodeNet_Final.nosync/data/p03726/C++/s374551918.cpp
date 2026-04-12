#pragma GCC optimize("trapv")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 + 100, INF = 1e9 * 1e9 + 10, MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char grid[502][502], ansBl[502][502], ansR[502][502];
bool usd[502];
ll col[SIZE], c[2];

vector<vector<ll>> gr;
ll dfs(int v, int par = -1) {
    ll cnt = 0;
    for (auto to : gr[v]) {
        if (to != par) {
            cnt += dfs(to, v);
        }
    }

    if (cnt >= 2) {
        cout << "First";
        exit(0);
    }
    cnt = !cnt;
    return cnt;
}
signed main()
{
    fastInp;

    ll n;
    cin >> n;

    gr.resize(n);
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    if (dfs(0)) {
        cout << "First";
        return 0;
    }

    cout << "Second";
    return 0;
}