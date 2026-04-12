#define _USE_MATH_DEFIMES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007;
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}


struct edge{
    int to, cost;
    edge(int To, int Cost): to(To), cost(Cost){};
};


long long prim(std::vector<std::vector<edge>>& G){
    int V(G.size());
    long long res(0);
    //std::pair<int, int> first: 距離　second: 頂点
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> que;
    std::vector<int> d(V, INF);
    d[0] = 0;
    que.push({0, 0});

    while(!que.empty()){
        std::pair<int, int> p = que.top(); que.pop();
        int v(p.second);
        if(d[v] < p.first) continue;
        d[v] = 0;
        res += p.first;
        for(edge &e : G[v]){
            if(d[e.to] > e.cost){
                d[e.to] = e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
    return res;
}

int main(){
    int N; std::cin >> N;
    std::vector<std::vector<edge>> G(N);
    //x,y,id と y,x,id
    std::vector<std::pair<std::pair<int, int>, int>> px(N), py(N);
    for(int i(0); i < N; ++i){
        px[i].second = py[i].second = i;
        std::cin >> px[i].first.first >> px[i].first.second;
        py[i].first.first = px[i].first.second;
        py[i].first.second = px[i].first.first;
    }
    std::sort(std::begin(px), std::end(px));
    std::sort(std::begin(py), std::end(py));
    for(int i(0), i_len(N-1); i < i_len; ++i){
        G[px[i].second].emplace_back(px[i+1].second, 
                                     std::abs(px[i].first.first - px[i+1].first.first));
        G[px[i+1].second].emplace_back(px[i].second, 
                                     std::abs(px[i].first.first - px[i+1].first.first));
        G[py[i].second].emplace_back(py[i+1].second, 
                                     std::abs(py[i].first.first - py[i+1].first.first));
        G[py[i+1].second].emplace_back(py[i].second, 
                                     std::abs(py[i].first.first - py[i+1].first.first));
    }
    std::cout << prim(G) << std::endl;
    return 0;
}
