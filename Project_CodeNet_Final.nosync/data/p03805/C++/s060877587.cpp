#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = s, i##_len=(n); i < i##_len; ++i)
#define FORS(i, s, n) for(int i = s, i##_len=(n); i <= i##_len; ++i)
#define VFOR(i, s, n) for(int i = s; i < (n); ++i)
#define VFORS(i, s, n) for(int i = s; i <= (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FORS(i, 0, n)
#define VREP(i, n) VFOR(i, 0, n)
#define VREPS(i, n) VFORS(i, 0, n)
#define RFOR(i, s, n) for(int i = s, i##_len=(n); i >= i##_len; --i)
#define RFORS(i, s, n) for(int i = s, i##_len=(n); i > i##_len; --i)
#define RREP(i, n) RFOR(i, n, 0)
#define RREPS(i, n) RFORS(i, n, 0)
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<decltype(v[0])>())
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end());

using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VD = vector<double>;
using VLL = vector<ll>;
using VS = vector<string>;

const int MOD = 1000000007;
const int INF = 1000000000;

template<class T>
bool chmax(T &a, const T &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T>
bool chmin(T &a, const T &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}


int V; //頂点数
vector<vector<int>> G;

int dfs(int v, vector<bool> visited){
    bool allVisit = true;
    REP(i, V) if(!visited[i]) allVisit = false;
    if(allVisit) return 1;

    int ret = 0;
    for(auto& e : G[v]){
        if(visited[e]) continue;
        visited[e] = true;
        ret += dfs(e, visited);
        visited[e] = false;
    }

    return ret;
}

int main(){
    int m; cin >> V >> m;
    G.resize(V);
    REP(i, m){
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].PB(b); G[b].PB(a);
    }
    vector<bool> visited(V, false);
    visited[0] = true;
    cout << dfs(0, visited) << "\n";
    return 0;
}
