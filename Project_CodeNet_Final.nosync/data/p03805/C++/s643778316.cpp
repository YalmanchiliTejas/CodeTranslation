#include <iostream>
#include <sstream>
#include <cstring>
#include <stack>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int dp[1 << 8][8];

int f(int mask, int last, VEC(VEC(int))& edges)
{
    const int n = edges.size();
    if (mask == (1 << n) - 1)
        return 1;

    int& ans = dp[mask][last];
    if (ans >= 0)
        return ans;

    ans = 0;
    for(int next : edges[last])
        if (!(mask & (1 << next)))
            ans += f(mask | (1 << next), next, edges);
    return ans;
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, M;
    cin >> N >> M;
    VEC(VEC(int)) edges(N);
    FOR(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    memset(dp, -1, sizeof dp);
    cout << f(1, 0, edges) << endl;
    return 0;
};
