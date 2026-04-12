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
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

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

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<bool> used(N);
    int ans = 0;
    auto dfs = [&](auto&& self, int cur = 0, int cnt = 1) -> void {
        for(int nxt : graph[cur]){
            if(used[nxt])   continue;
            if(cnt == N - 1){
                ++ans;
                return;
            }
            used[nxt] = true;
            self(self, nxt, cnt + 1);
            used[nxt] = false;
        }
    };
    used[0] = true;
    dfs(dfs);
    cout << ans << endl;
}