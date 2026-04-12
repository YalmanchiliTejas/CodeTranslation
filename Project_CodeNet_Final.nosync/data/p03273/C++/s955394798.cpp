#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

int h, w;
vector<string> get_target_table(const vector<string> &table)
{
    vector<string> res;
    for (int i = 0; i < h; i++)
    {
        bool not_black = true;
        for (int j = 0; j < w; j++)
        {
            if (table[i][j] == '#')
                not_black = false;
        }
        if (not_black == false)
            res.push_back(table[i]);
    }
    return res;
}

void solve()
{
    cin >> h >> w;
    vector<string> table(h);
    for(int i = 0; i < h; i++) cin >> table[i];

    vector<string> ans = get_target_table(table);

    vector<int> v;
    for(int j = 0; j < w; j++)
    {
        bool not_black = true;
        for(int i = 0; i < h; i++)
        {
            if(table[i][j] == '#') not_black = false;
        }
        if(not_black) v.push_back(j);
    }

    reverse(v.begin(), v.end());
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < w; j++)
        {
            bool ok = true;
            for(int k = 0; k < v.size(); k++)
            {
                if(v[k] == j) ok = false;
            }
            if(ok) cout << ans[i][j];
        }
        cout << endl;
    }
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}