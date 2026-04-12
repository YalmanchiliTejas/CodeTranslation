#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <climits>
#include <iostream>
#define ATCODER 

class union_find
{
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int node_num;
public:
    union_find(int node_num);
    void unite(int x, int y);
    int find(int x);
};

union_find::union_find(int node_num):
    parent(node_num + 1, 0),
    rank(node_num + 1, 0)
{
    for (int i = 0; i <= node_num; i++) {
        parent[i] = i;
    }
}

void union_find::unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    //既に同じ根なら、同じ所属なので何もしない
    if (x_root == y_root) return;
    //ランクが大きい方に小さい方をくっつける
    //結合後のランクは大きい方になる。
    if (rank[x_root] > rank[y_root]) {
        parent[y_root] = x_root;
    }
    else {
        parent[x_root] = y_root;
        if(rank[x_root] == rank[y_root]){
            //ランクが等しい場合は、必ずランクが1上がる。
            rank[y_root]++;
        }
    }
}

int union_find::find(int x) {
    if (x != parent[x]) {
        // findの結果を各parentに入れることで経路を圧縮。
        //ただし、変更コストが大きいのでランクは変えてない。
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

class edge {
public:
    edge(int to, long long cost);
    int get_to() const;
    long long get_cost() const;
private:
    int to;
    long long cost;
};

edge::edge(int to, long long cost) : to(to), cost(cost) {}

int edge::get_to() const { return to; }

long long edge::get_cost() const { return cost; }

class kruskal
{
private:
    //unordered_mapを使って隣接リストを構築
    //first:接続元、second:辺のコストと接続先
    std::unordered_map<int, std::vector<edge>> adj_list;
    //最小全域木の隣接リスト
    std::unordered_map<int, std::vector<edge>> MST_list;
    int node_num;
    long long MST_cost;
public:
    kruskal(const int node_num, const std::unordered_map<int, std::vector<edge>>& adj_list);
    long long get_MST_cost() const;
    std::unordered_map<int, std::vector<edge>> get_MST_list();
    void calc_MST();
};

kruskal::kruskal(const int node_num, const std::unordered_map<int, std::vector<edge>>& adj_list):
    adj_list(adj_list),
    node_num(node_num),
    MST_cost(0)
{
}

void kruskal::calc_MST() {
    //辺のリスト。firstがコスト、secondがつながっている両頂点
    std::vector<std::pair<long long, std::pair<int, int>>> edge_list;

    //隣接リストから辺のリストへ変換
    for (auto &v : adj_list) {
        for (auto &e : v.second) {
            edge_list.push_back(std::make_pair(e.get_cost(), 
                        std::make_pair(v.first, e.get_to())));
        }
    }

    std::sort(edge_list.begin(), edge_list.end());

    union_find uf(node_num + 1);
    MST_cost = 0;
    MST_list.clear();
    for (auto &ed : edge_list) {
        int v1 = ed.second.first;
        int v2 = ed.second.second;
        long long cost = ed.first;
        //同じ根を持つなら、既に両頂点は同じ木の中
        //=辺を追加するとループができるのでなにもしない。
        if (uf.find(v1) != uf.find(v2)) {
            //根が異なる場合、両頂点間に辺を追加
            uf.unite(v1, v2);
            MST_cost += cost;
            MST_list[v1].push_back(edge(v2, cost));
            MST_list[v2].push_back(edge(v1, cost));
        }
    }
}

long long kruskal::get_MST_cost() const {
    return MST_cost;
}

std::unordered_map<int, std::vector<edge>> kruskal::get_MST_list() {
    return MST_list;
}




int main()
{
#ifndef ATCODER
    std::unordered_map<int, std::vector<edge>> adj_list;
    int N, M;
    std::cin >> N >> M;
    if (M == 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < M; i++) {
        int s, t, w;
        std::cin >> s >> t >> w;
        adj_list[s].push_back(edge(t, w));
        adj_list[t].push_back(edge(s, w));
    }
    kruskal krus(N, adj_list);
    krus.calc_MST();
    std::cout << krus.get_MST_cost() << "\n";
    std::unordered_map<int, std::vector<edge>> MST = krus.get_MST_list();
    return 0;
#else
    std::vector<std::pair<long long, int>> x_citys;
    std::vector<std::pair<long long, int>> y_citys;
    std::unordered_map<int, std::vector<edge>> adj_list;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        x_citys.push_back(std::make_pair(x, i + 1));
        y_citys.push_back(std::make_pair(y, i + 1));
    }
    std::sort(x_citys.begin(), x_citys.end());
    std::sort(y_citys.begin(), y_citys.end());
    std::vector<std::pair<int, int>> adj_pair_list;
    for (int i = 0; i < N - 1; i++) {


        adj_list[x_citys[i].second].push_back(edge(x_citys[i + 1].second,
            abs(x_citys[i + 1].first - x_citys[i].first)));
        adj_list[x_citys[i + 1].second].push_back(edge(x_citys[i].second,
            abs(x_citys[i + 1].first - x_citys[i].first)));
        adj_list[y_citys[i].second].push_back(edge(y_citys[i + 1].second,
            abs(y_citys[i + 1].first - y_citys[i].first)));
        adj_list[y_citys[i + 1].second].push_back(edge(y_citys[i].second,
            abs(y_citys[i + 1].first - y_citys[i].first)));

    }

    kruskal krus(N, adj_list);
    krus.calc_MST();
    std::cout << krus.get_MST_cost() << "\n";
    return 0;

#endif

}