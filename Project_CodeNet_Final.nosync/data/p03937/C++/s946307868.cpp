#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<string> g;
vector<vector<bool>> used;

bool dfs (ll x, ll y)
{
    bool f = 0;
    ll nx = 0;
    ll ny = 0;
    
    used[y][x] = 1;
    
    for (int i = 0; i < dx.size(); ++i)
    {
        ll nextx = x + dx[i];
        ll nexty = y + dy[i];
        if (nextx >= 0 && nexty >= 0 && nextx < g[0].size() && nexty < g.size() && g[nexty][nextx] == '#')
        {
            if (used[nexty][nextx])
            {
                continue;
            }
            if (f)
            {
                return 0;
            }
            f = 1;
            if (i == 0 || i == 2)
            {
                nx = nextx;
                ny = nexty;
            }
        }
    }
    if (!f)
    {
        if (x == g[0].size() - 1 && y == g.size() - 1)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        if (x == g[0].size() - 1 && y == g.size() - 1)
        {
            return 0;
        }
    }
    ll ret = dfs(nx, ny);
    return ret;
}


int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    used = vector<vector<bool>>(h, vector<bool>(w));
    
    for (int i = 0; i < h; ++i)
    {
        cin >> a[i];
    }
    g = a;
    
    if (dfs(0 ,0))
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    
    return 0;
}