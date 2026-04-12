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
#include <cstring>

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
#include <list>
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

int dp[3001][3001];
bool visited[3001][3001];
int N;
int A[3001];

int rec(int left, int right) {
    if (left > right) return 0;
    if (visited[left][right]) return dp[left][right];
    visited[left][right] = true;

    int diff = N - (right - left + 1);
    if (diff % 2 == 0) {
        dp[left][right] = max(rec(left + 1, right) + A[left], rec(left, right - 1) + A[right]);
    } else {
        dp[left][right] = min(rec(left + 1, right) - A[left], rec(left, right - 1) - A[right]);
    }

    return dp[left][right];
}

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << rec(0, N - 1) << endl;
}