#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <unordered_map>
#include <functional>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

const long long MOD = 1000000007;

class Direct_Graph {
    public:
    struct Edge { 
        int to; long long cost;
    };
    std::vector<std::vector<Edge>> G;
    int node_num;
    Direct_Graph() {}
    Direct_Graph(const int node_num_in) {
        node_num = node_num_in;
        G.resize(node_num);
    }
    void add_edge(const int from, const int to, const long long cost) {
        Edge edge; edge.to = to; edge.cost = cost;
        G[from].push_back(edge);
    }
    void add_edge_both(const int node1, const int node2, const long long cost) {
        add_edge(node1, node2, cost);
        add_edge(node2, node1, cost);
    }

    std::vector<long long> Dijkstra(int s, const long long dist_inf, std::vector<long long>& path_num) {
        std::vector<long long> dist; dist.resize(node_num);
        path_num.resize(node_num);
        for (int i = 0; i < dist.size(); i++) {
            dist[i] = dist_inf;
            path_num[i] = 0;
        }
        typedef std::pair<long long, int> Pair;

        std::priority_queue <Pair, std::vector<Pair>, std::greater<Pair>> que;
        dist[s] = 0;
        path_num[s] = 1;
        que.push(Pair(0, s));

        while (!que.empty()) {
            Pair pair = que.top(); que.pop();
            int v = pair.second;
            if (dist[v] < pair.first) { continue; }
            for (Edge edge : G[v]) {
                if (dist[v] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[v] + edge.cost;
                    path_num[edge.to] = path_num[v];
                    que.push(Pair(dist[edge.to], edge.to));
                } else if (dist[v] + edge.cost == dist[edge.to]) {
                    path_num[edge.to] = (path_num[edge.to] + path_num[v]) % MOD;
                }
            }
        }
        return dist;
    }
};

const int MAX_N = 1000050;
const int MAX_M = 2000050;
const long long DIST_INF = (long long)1000000007 * MAX_M;
int N, M, S, T;
int U[MAX_M], V[MAX_M];
long long D[MAX_M];

Direct_Graph dg = Direct_Graph(MAX_N);

int main(int argc, char **argv) {
    std::cin >> N >> M;
    std::cin >> S >> T;

    for (int i = 1; i <= M; i++) {
        std::cin >> U[i] >> V[i] >> D[i];
    }

    for (int i = 1; i <= M; i++) {
        dg.add_edge_both(U[i], V[i], D[i]);
    }

    std::vector<long long> distS, distT, pnS, pnT;
    distS = dg.Dijkstra(S, DIST_INF, pnS);
    distT = dg.Dijkstra(T, DIST_INF, pnT);

    assert(pnS[T] == pnT[S]);
    assert(distS[T] == distT[S]);
    //std::cout << "check:" << pnS[T] << std::endl;

    long long tmp = 0;
    for (int i = 1; i <= N; i++) {
        if (distS[i] == distT[i] && distS[i] * 2 == distS[T]) {
            long long val = (pnS[i] * pnT[i]) % MOD;
            tmp = tmp + (val * val) % MOD;
            tmp = tmp % MOD;
        }
    }

    for (int i = 1; i <= M; i++) {
        if (distS[U[i]] + D[i] + distT[V[i]] == distS[T] &&
            distS[U[i]] + D[i] > distT[V[i]] &&
            distT[V[i]] + D[i] > distS[U[i]]
        ) {
            long long val = (pnS[U[i]] * pnT[V[i]]) % MOD;
            tmp = tmp + (val * val) % MOD;
            tmp = tmp % MOD;
        }
        if (distS[V[i]] + D[i] + distT[U[i]] == distS[T] &&
            distS[V[i]] + D[i] > distT[U[i]] &&
            distT[U[i]] + D[i] > distS[V[i]]
        ) {
            long long val = (pnS[V[i]] * pnT[U[i]]) % MOD;
            tmp = tmp + (val * val) % MOD;
            tmp = tmp % MOD;
        }
    }

    long long ret = MOD + (pnS[T] * pnT[S]) % MOD - tmp; 

    std::cout << ret % MOD << std::endl;
    
    return 0;
}