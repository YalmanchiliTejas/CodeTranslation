#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class UnionFind{ //連結判定
private:
    std::vector<int> parent; //parent[i] = parent of node i
    std::vector<int> rank;
    std::vector<int> size;
public:
    //constructor
    UnionFind(int N){
        for(int i=0; i<N; i++) parent.push_back(i); //parent = [0,1,..,N-1]
        for(int i=0; i<N; i++) rank.push_back(0); //rank = [0,0,..,0]
        for(int i=0; i<N; i++) size.push_back(1);
    }
    //initialize
    void init(int N){
        parent.clear();
        rank.clear();
        size.clear();
        for(int i=0; i<N; i++) parent.push_back(i); //parent = [0,1,..,N-1]
        for(int i=0; i<N; i++) rank.push_back(0); //rank = [0,0,..,0]
        for(int i=0; i<N; i++) size.push_back(1);
    }
    int root(int a){
        if(parent[a] == a) return a;
        return parent[a] = root(parent[a]); //親が自分自身になるまで再帰を呼び出す & 経路圧縮 
    }
    void unite(int a, int b){
        int rootA = root(a);
        int rootB = root(b);
        if(rootA == rootB) return; //ノードa, bがすでに連結しているとき
        //次数の大きい方を親として連結
        if(rank[rootA] < rank[rootB]){
            size[rootB] += size[rootA];
            parent[rootA] = rootB;
        }
        else{
            size[rootA] += size[rootB];
            parent[rootB] = rootA;
            if(rank[rootA] == rank[rootB]) rank[rootA]++;
        }
    }
    bool same(int a, int b){
        return root(a) == root(b); //ノードa, bが同じ木に属するかどうか
    }
    int get_size(int a){
        return size[root(a)];
    }
};

class Edge{
public:
    int from, to;
    long long cost;
    Edge(): from(0), to(0), cost(0){}
    Edge(int u, int v, long long w): from(u), to(v), cost(w){}
    ~Edge(){}
    bool operator<(const Edge &e)const{
        return cost < e.cost;
    }
};

int main()
{
    using P = std::pair<long long, int>;

    int N;
    std::cin >> N;
    std::vector<P> x(N), y(N);
    for(int i=0; i<N; i++){
        scanf(" %lld %lld", &x[i].first, &y[i].first);
        x[i].second = i; y[i].second = i;
    }

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::vector<Edge> edge;
    for(int i=0; i<N-1; i++){
        edge.push_back(Edge(x[i].second, x[i+1].second, x[i+1].first - x[i].first));
        edge.push_back(Edge(y[i].second, y[i+1].second, y[i+1].first - y[i].first));
    }
    std::sort(edge.begin(), edge.end());

    long long min = 0;
    UnionFind uf(N);
    for(auto &&itr = edge.begin(); itr != edge.end(); itr++){
        int u = itr->from, v = itr->to;
        if(!uf.same(u, v)){
            uf.unite(u, v); min += itr->cost;
        }
    }
    std::cout << min << std::endl;
}