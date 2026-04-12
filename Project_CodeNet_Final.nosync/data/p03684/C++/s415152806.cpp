#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;
typedef pair<int, Pii> PiP;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

struct edge{int to, cost;};

class Graph
{
public:
    int V;
    vector<vector<edge>> G;

    Graph(int V): V(V){
        G = vector<vector<edge>>(V, vector<edge>(0));
    }

    void add_edge(int from, int to, int cost){
        G[from].push_back(edge({to, cost}));
    }

    void add_edge2(int v1, int v2, int cost){
        add_edge(v1, v2, cost);
        add_edge(v2, v1, cost);
    }

};

class union_find final
{
    using data_type = int64_t;
    using size_type = uint64_t;

    static constexpr data_type none = -1;

    // data_[index]の値が親要素を表す(noneはroot)
    std::vector<data_type> data_;
    // rootの集合
    std::set<data_type> roots_;
    // そのグループの要素の数
    std::vector<size_type> size_;

    // indexのrootを求める
    data_type root(data_type index)
    {
        // グループ番号がnoneならそれがroot
        if(data_[index] == none)
            return index;
        // 親へのindexをrootに付け替える(高速化)
        data_[index] = root(data_[index]);
        return data_[index];
    }
public:

    union_find(data_type size)
        : data_(size, none), size_(size, 1)
    {
    }

    // aとbを同じグループにする
    void unite(data_type a, data_type b)
    {
        a = root(a);
        b = root(b);
        
        // aとbのrootが同じならすでに同じグループ
        if(a == b) return;
        
        // 要素の多い方に付け替える(高速化)
        if(size_[a] < size_[b]) {
            data_[b] = a;
            size_[a] = size_[a] + size_[b];
            roots_.erase(b);
            roots_.insert(a);
        } else {
            data_[a] = b;
            size_[b] = size_[a] + size_[b];
            roots_.erase(a);
            roots_.insert(b);
        }
    }

    bool is_union(data_type a, data_type b)
    {
        return root(a) == root(b);
    }
    
    // ↓あると便利なの

    const std::set<data_type>& roots() const
    {
        return roots_;
    }

    size_type maximum() const
    {
        return *std::max_element(size_.begin(), size_.end());
    }
    size_type minimum() const
    {
        return *std::min_element(size_.begin(), size_.end());
    }
};

signed main(){

    int N; cin >> N;
    vec x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];
    vector<Pii> Px(N), Py(N);
    REP(i, N){
        Px[i] = Pii(x[i], i);
        Py[i] = Pii(y[i], i);
    }
    SORT(Px);
    SORT(Py);

    Graph G(N);
    REP(i, N - 1){
        G.add_edge2(Px[i].second, Px[i + 1].second, Px[i + 1].first - Px[i].first);
        G.add_edge2(Py[i].second, Py[i + 1].second, Py[i + 1].first - Py[i].first);
    }

    priority_queue<Pii> que;
    REP(k, G.G[0].size()) que.push(Pii(-1 * G.G[0][k].cost, G.G[0][k].to));  
    vector<bool> used(N, false);
    used[0] = true;
    int n = 1;
    int ans = 0;
    while(n < N){
        Pii p = que.top(); que.pop();
        if(used[p.second]) continue;
        used[p.second] = true;
        n++;
        ans += -1 * p.first;
        REP(k, G.G[p.second].size()) que.push(Pii(-1 * G.G[p.second][k].cost, G.G[p.second][k].to));
    }
    cout << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}