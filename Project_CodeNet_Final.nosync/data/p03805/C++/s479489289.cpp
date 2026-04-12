#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <tuple>
#include <utility>
#include <limits>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <cassert>

using namespace std;

template<typename T, size_t N>
constexpr size_t NELEMS(T (&)[N]) { return N; }

template<typename InputIt>
void PRINT_RANGE(InputIt first, InputIt last)
{
    for(; first != last; ++first)
        cout << *first << (first==last ? "" : " ");
    cout << "\n";
}

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

#define DEBUG
#undef DEBUG

using ll  = long long;
using ull = unsigned long long;

int N, M;
int G[9][9] = {};

bool visited[9] = {};
int cnt = 0;

void dfs(int v)
{
    if(visited[v]) return;
    visited[v] = true;

    //cout << v << "\n";

    if(all_of(visited+1, visited+N+1, [](bool x) { return x; })) {
        visited[v] = false;
        ++cnt;
        return;
    }

    FOR(dst, 1, N+1) {
        if(G[v][dst]) {
            dfs(dst);
        }
    }

    visited[v] = false;
}

void solve()
{
    dfs(1);

    cout << cnt << "\n";
}

int main()
{
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }

    solve();

    return 0;
}
