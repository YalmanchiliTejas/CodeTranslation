#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>
#include <stack>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;
using Graph = Vvec<int>;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

void graphParse(Graph& graph, int num_edge, bool is_bidirectional){
    int u, v;
    for(int i=0; i<num_edge; i++){
        cin >> u >> v;
        u--; v--;
        graph[u].emplace_back(v);
        if(is_bidirectional) graph[v].emplace_back(u);
    }
}

void dfs(Graph& graph, Vvec<int>& dp, int tmp, int from){
    if(from != -1 && graph[tmp].size() == 1){
        dp[tmp][0] = 1;
        dp[tmp][1] = 0;
        return;
    }

    vector<ll> bs(graph[tmp].size()+1);
    int j = 0;
    for(auto& to: graph[tmp]){
        if(to != from){
            dfs(graph, dp, to, tmp);
            bs[j++] = dp[to][1];
        }
    }
    bs[j] = true;
    // cout << j <<" " << bs.size() << endl;
    while(j>0){
        bs[j-1] = bs[j-1] & bs[j];
        j--;
    }

    dp[tmp][0] = bs[0];
    bool b = true;
    for(auto& to: graph[tmp]){
        if(to != from){
            dp[tmp][1] |= b & dp[to][0] & bs[++j];
            b &= dp[to][1];
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Graph graph(N);
    graphParse(graph, N-1, true);

    Vvec<int> dp(N, vector<int>(2));
    dfs(graph, dp, 0, -1);

    cout << ((dp[0][1]) ? "Second\n" : "First\n");
}