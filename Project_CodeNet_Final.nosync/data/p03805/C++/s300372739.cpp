#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int adj[10][10];
int visited[10];

void solve()
{
    int N;
    cin >> N;
    int M;
    cin >> M;

    REP0(i, M)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b]++;
        adj[b][a]++;
    }

    vector<int> perm;
    FOR(i, 2, N + 1)
    { // 1が始点なのは固定
        perm.push_back(i);
    }

    int ans = 0;

    do
    {
        if (adj[1][perm[0]] != 1)
            continue;
        bool path = true;
        REP1(i, N - 2)
        {
            path = path and adj[perm[i - 1]][perm[i]];
        }
        if (path)
            ans++;
    } while (next_permutation(perm.begin(), perm.end()));

    std::cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}