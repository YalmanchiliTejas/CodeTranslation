#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>



using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const double EPS = (1e-10);
long long const MOD = 1000000007;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fastInput() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int dfs(int crt, int color, vector<vector<int>> &G, vector<int> &v) {
    v[crt] = color;
    color ^= 1;
    int ret = 0;
    for (int i = 0; i < G[crt].size(); i++) {
        int nv = G[crt][i];
        if (v[nv] == -1) {
            ret = min(dfs(nv, color, G, v), ret);
        }
        if (v[nv] != color) return -1;
    }
    return ret;
}

vector<int> solve(int N, int M) {
    vector<vector<int>> G(N);

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    set<int> s;
    for (int i = 0; i < N; i++) {
        vector<int> v(N, -1);
        int check = dfs(i, 0, G, v);
        if (check == -1) continue;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (v[j] == 1) cnt++;
            if (j == N-1) {
                if (cnt % 2) break;
                s.insert(cnt/2);
            }
        }
    }
    
    vector<int> ret;
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        ret.push_back(*itr);
    }
    return ret;
}

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> D(M);
    for (int i = 0; i < M; i++) {
        cin >> D[i];
        D[i]--;
    }
    vector<vector<int>> G(M);
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++) {
            int v; cin >> v;
            v--;
            int u = M;
            int flag = 1;
            for (int j = 0; j < M; j++) {
                if (i == D[j]) {
                    u = j;
                }
                if (v == D[j]) {
                    v = j;
                    flag = 0;
                }
            }
            if (u == M) continue;
            if (flag) v = M;
            G[u].push_back(v);
        }
    }
    
    vector<int> state((1 << M));
    int crtState = (1 << (M)) - 1;
    queue<int> q;
    q.push(crtState);
    state[crtState] = 1;
    while (!q.empty()) {
        crtState = q.front();
        q.pop();
        for (int i = 0; i < K; i++) {
            int nextState = 0;
            for (int j = 0; j < M; j++) {
                if ((1 << j) & crtState) {
                    if (G[j][i] == M) continue;
                    nextState |= (1 << G[j][i]);
                }
            }
            if (state[nextState] == 0) {
                state[nextState] = state[crtState] + 1;
                q.push(nextState);
            }
        }
    }
    cout << state[0] - 1 << endl;
}



