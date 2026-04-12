#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
#include <cstring>
using namespace std;

using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1001001001;
// constexpr int mod = 1000000007;
constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, X, M;
    cin >> N >> X >> M;
    vector<vector<int>> graph(M), rev(M);
    for(int i = 0; i < M; ++i){
        ll v = (ll)i * i % M;
        graph[i].emplace_back(v);
        rev[v].emplace_back(i);
    }
    vector<int> vs;
    vector<bool> used(M, false);
    auto dfs = [&](auto&& self, int from) -> void {
        used[from] = true;
        for(int to : graph[from]){
            if(!used[to])   self(self, to);
        }
        vs.emplace_back(from);
    };
    for(int v = 0; v < M; ++v){
        if(!used[v])    dfs(dfs, v);
    }
    reverse(vs.begin(), vs.end());

    vector<int> scc_id(M, -1);
    int K = 0;
    auto rdfs = [&](auto&& self, int from) -> void {
        scc_id[from] = K;
        for(int to : rev[from]){
            if(scc_id[to] == -1)    self(self, to);
        }
    };
    for(int v : vs){
        if(scc_id[v] == -1){
            rdfs(rdfs, v);
            ++K;
        }
    }
    vector<vector<int>> scc_set(K);
    for(int i = 0; i < M; ++i){
        scc_set[scc_id[i]].emplace_back(i);
    }

    ll ans = X;
    --N;
    X = graph[X][0];
    while(N > 0){
        if(X == 0)  break;
        if(scc_set[scc_id[X]].size() == 1){
            if(X == graph[X][0]){
                ans += X * N;
                N = 0;
            }
            else{
                ans += X;
                X = graph[X][0];
                --N;
            }
        }
        else{
            int loop = scc_set[scc_id[X]].size();
            ll total = 0;
            for(int v : scc_set[scc_id[X]]){
                total += v;
            }
            ans += total * (N / loop);
            N %= loop;
            while(N-- > 0){
                if(X == 0){
                    N = 0;
                    break;
                }
                ans += X;
                X = graph[X][0];
            }
        }
    }
    cout << ans << endl;
}