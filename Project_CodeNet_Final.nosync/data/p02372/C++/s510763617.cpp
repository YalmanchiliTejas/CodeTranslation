#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
//#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

struct Edge {
    int to;
    int w;
};

using Edges = std::vector<std::vector<Edge>>;

struct Memo {
    int parent;
    std::vector<std::pair<int, int>> childHeights;
};

int dfs(int i, const Edges& edges, std::vector<Memo>& memo) {
    memo[i].childHeights.reserve(edges[i].size());
    for(auto edge: edges[i]) {
        if(edge.to != memo[i].parent) {
            memo[edge.to].parent = i;
            memo[i].childHeights.push_back(std::make_pair(edge.to, edge.w + dfs(edge.to, edges, memo)));
        }
    }
    std::sort(begin(memo[i].childHeights), end(memo[i].childHeights), [](auto x, auto y){return x.second > y.second;});
    if(memo[i].childHeights.empty()) return 0;
    else return memo[i].childHeights[0].second;//std::max_element(begin(memo[i].childHeights), end(memo[i].childHeights), [](auto x, auto y){return x.second > y.second;})->second;
}

void dfs2(int i, const Edges& edges, std::vector<Memo>& memo, std::vector<int>& ans, int pHeight) {
    auto& childHeights = memo[i].childHeights;
    if(childHeights.size() == 0) {
        ans[i] = pHeight;
    } else if(childHeights.size() == 1) {
        ans[i] = std::max(pHeight, childHeights[0].second);
        for(auto edge: edges[i]) {
            if(edge.to != memo[i].parent) dfs2(edge.to, edges, memo, ans, pHeight + edge.w);
        }
    } else {
        std::sort(begin(childHeights), end(childHeights), [](auto x, auto y){return x.second > y.second;});
        ans[i] = std::max(pHeight, childHeights.front().second);
        for(auto edge: edges[i]) {
            if(edge.to != memo[i].parent) {
                if(edge.to == childHeights.front().first) dfs2(edge.to, edges, memo, ans, std::max(pHeight, childHeights[1].second) + edge.w);
                else dfs2(edge.to, edges, memo, ans, std::max(pHeight, childHeights[0].second) + edge.w);
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    Edges edges(n, std::vector<Edge>());
    while(--n) {
        int s, t, w;
        std::cin >> s >> t >> w;
        edges[s].push_back(Edge{t, w});
        edges[t].push_back(Edge{s, w});
    }

    std::vector<int> ans(edges.size(), 0);
    std::vector<Memo> memo(edges.size(), Memo{-1, std::vector<std::pair<int, int>>()});
    ans[0] = dfs(0, edges, memo);

    dfs2(0, edges, memo, ans, 0);

    for(auto val: ans)
        std::cout << val << "\n";
    std::cout << std::flush;

    return 0;
}

