#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
int msearch(vector<vector<bool>> &g)
{
    int ans = 0;
    int p[N - 1];
    rep(i, 0, N - 1)
    {
        p[i] = i + 2;
    }
    do
    {
        bool check = true;
        if (!g[1][p[0]])
            continue;
        rep(i, 0, N - 2)
        {
            if (!g[p[i]][p[i + 1]])
            {
                check = false;
                break;
            }
        }
        // rep(i, 0, N - 1) cout << p[i] << ' ';
        // cout << endl;
        if (check)
            ++ans;
    } while (next_permutation(&p[0], &p[N - 1]));
    return ans;
}
void func()
{
    cin >> N >> M;
    vector<vector<bool>> g(N + 1, vector<bool>(N + 1, false));
    int ai, bi;
    rep(i, 0, M)
    {
        cin >> ai >> bi;
        g[ai][bi] = true;
        g[bi][ai] = true;
    }
    cout << msearch(g) << endl;
}
int main()
{
    func();
}