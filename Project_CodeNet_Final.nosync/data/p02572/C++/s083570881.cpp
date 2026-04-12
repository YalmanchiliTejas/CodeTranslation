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
#include <cassert>

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
#include <stack>

// type
#include <cstdint>
#include <functional>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
template <class T> using MaxHeap = priority_queue<T>;
template <class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* ---------- Functions */
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i =0; i < N; i++) cin >> A[i];

    vector<int> S(N+1, 0);
    for (int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }
    int sum = S[N];

    int ret = 0;
    for (int i= 0; i <= N-2; i++) {
        int tmp = sum - S[i+1] + MOD;
        tmp %= MOD;
        ret += (tmp * A[i]) % MOD;
        ret %= MOD;
    }

    cout << ret << endl;
    return 0;
}