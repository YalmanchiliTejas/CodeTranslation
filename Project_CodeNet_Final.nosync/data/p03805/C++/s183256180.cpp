#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void msearch(vector<vector<bool>> &g, bool *isv, int v, int &ans)
{
    bool visited = true;
    rep(i, 1, N + 1)
    {
        if (!isv[i])
        {
            visited = false;
            break;
        }
    }
    if (visited)
    {
        ++ans;
        return;
    }
    rep(i, 1, N + 1)
    {
        if (g[v][i] && !isv[i])
        {
            isv[i] = true;
            msearch(g, isv, i, ans);
            isv[i] = false;
        }
    }
}
void func()
{
    cin >> N >> M;
    vector<vector<bool>> g(N + 1, vector<bool>(N + 1, false));
    bool isv[N + 1] = {};
    isv[1] = true;
    int ai, bi;
    rep(i, 0, M)
    {
        cin >> ai >> bi;
        g[ai][bi] = true;
        g[bi][ai] = true;
    }
    int ans = 0;
    msearch(g, isv, 1, ans);
    cout << ans << endl;
}
int main()
{
    func();
}