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

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
int N;
const int MAX_N = 3001;
int dp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int A[MAX_N];

int rec(int i, int j) {
    if (j < i) return 0;
    if (visited[i][j]) return dp[i][j];

    visited[i][j] = true;

    if (N % 2 == (j - i + 1) % 2) {
        dp[i][j] = max(A[i] + rec(i+1, j), A[j] + rec(i, j-1));
    } else {
        dp[i][j] = min(-A[i] + rec(i+1, j), -A[j] + rec(i, j-1));
    }

    return dp[i][j];
}

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    cout << rec(0, N-1) << endl;

    return 0;
}