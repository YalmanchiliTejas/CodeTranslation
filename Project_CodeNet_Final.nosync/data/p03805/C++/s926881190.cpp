#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define P pair<ll, ll>
#define INF 10e6
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> lst;
    rep(i, 0, n) lst.push_back(i);
    int ans = 0;
    do
    {
        if (lst[0] != 0)
            break;
        bool flag = true;
        rep(i, 0, n - 1) if (find(all(g[lst[i]]), lst[i + 1]) == g[lst[i]].end()) flag = false;
        if (flag)
            ans++;
    } while (next_permutation(all(lst)));
    cout << ans << endl;
}