/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
int dfs(int rank, int cnt) {
    if (rank == 0) return 1;

    int total_cnt = (int) pow(2, rank + 2) - 3;
    int part_cnt = (total_cnt - 3) / 2;

    if (cnt == 1) return 0;
    if (cnt <= 1 + part_cnt) return dfs(rank-1, cnt - 1);
    if (cnt == 1 + part_cnt + 1) return dfs(rank-1, part_cnt) + 1;
    if (cnt <= 2 + part_cnt * 2) return dfs(rank-1, part_cnt) + 1 + dfs(rank-1, cnt - 2 - part_cnt);
    return dfs(rank-1, part_cnt) * 2 + 1;
}

signed main() {
    int L, X;
    cin >> L >> X;
    cout << dfs(L, X);

    return 0;
}