#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define LLINF (1e18)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }
    vector<vector<bool>> check(h, vector<bool>(w, true));
    for (int i = 0; i < h; i++)
    {
        bool flg = true;
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '#')
            {
                flg = false;
            }
        }
        if (flg)
        {
            for (int j = 0; j < w; j++)
            {
                check[i][j] = false;
            }
        }
    }
    for (int i = 0; i < w; i++)
    {
        bool flg = true;
        for (int j = 0; j < h; j++)
        {
            if (grid[j][i] == '#')
            {
                flg = false;
            }
        }
        if (flg)
        {
            for (int j = 0; j < h; j++)
            {
                check[j][i] = false;
            }
        }
    }
    vector<string> ans;
    for (int i = 0; i < h; i++)
    {
        string tmp = "";
        for (int j = 0; j < w; j++)
        {
            if (check[i][j])
            {
                tmp += grid[i][j];
            }
        }
        if (tmp != "")
        {
            ans.push_back(tmp);
        }
    }
    for (auto a : ans)
    {
        cout << a << endl;
    }
}