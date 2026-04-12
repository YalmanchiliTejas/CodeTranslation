#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 100005;
const int MAX_M = 200005;

template<typename _Key, class _Compare=less<_Key> > class BaseHeap {
private:
    set<_Key, _Compare> heap;

public:
    BaseHeap(){}
    bool empty() const {
        return heap.empty();
    }
    void insert(const _Key& key){
        heap.insert(key);
    }
    void erase(const _Key& key){
        heap.erase(heap.find(key));
    }
    const _Key& find_min() const {
        return *heap.begin();
    }
};

template<typename _Key, class _Compare=less<_Key> > class MeldableHeapNode {
private:
    BaseHeap<_Key, _Compare> bheap;
    const _Key key;
    MeldableHeapNode *par;
    unsigned int rank;

public:
    MeldableHeapNode(const _Key& _key) : key(_key), par(this), rank(0u){
        bheap.insert(_key);
    }
    bool empty() const {
        return bheap.empty();
    }
    const _Key& get_key() const {
        return key;
    }
    MeldableHeapNode*& get_parent(){
        return par;
    }
    MeldableHeapNode*& get_grandparent(){
        return par->get_parent();
    }
    unsigned int& get_rank(){
        return rank;
    }
    bool is_root() const {
        return this == par;
    }
    void insert(const _Key& key){
        bheap.insert(key);
    }
    void erase(const _Key& key){
        bheap.erase(key);
    }
    const _Key& find_min() const {
        return bheap.find_min();
    }
};

template<typename _Key, class _Compare=less<_Key> > class MeldableHeaps {
private:
    stack<MeldableHeapNode<_Key, _Compare>*> free_pointer;
    void cut_path(MeldableHeapNode<_Key, _Compare> *cur_heap){
        if(!cur_heap->is_root()){
            cut_path(cur_heap->get_parent());
            unhang(cur_heap, cur_heap->get_parent());
        }
    }
    void compress_path(MeldableHeapNode<_Key, _Compare> *cur_heap){
        if(!cur_heap->is_root()){
            compress_path(cur_heap->get_parent());
            hang(cur_heap, cur_heap->get_grandparent());
        }
    }
    void hang(MeldableHeapNode<_Key, _Compare> *heap1,
                                            MeldableHeapNode<_Key, _Compare> *heap2){
        if(!heap1->empty()) heap2->insert(heap1->find_min());
        heap1->get_parent() = heap2;
    }
    void unhang(MeldableHeapNode<_Key, _Compare> *heap1,
                                            MeldableHeapNode<_Key, _Compare> *heap2){
        heap2->erase(heap1->find_min());
    }

public:
    MeldableHeaps(){}
    ~MeldableHeaps(){
        while(!free_pointer.empty()){
            MeldableHeapNode<_Key, _Compare> *heap = free_pointer.top();
            free_pointer.pop();
            delete heap;
        }
    }
    MeldableHeapNode<_Key, _Compare> *make_heap(const _Key& key){
        free_pointer.push(new MeldableHeapNode<_Key, _Compare>(key));
        return free_pointer.top();
    }
    MeldableHeapNode<_Key, _Compare> *insert(MeldableHeapNode<_Key, _Compare> *heap,
                                                const _Key& key){
        assert(heap->is_root());
        MeldableHeapNode<_Key, _Compare> *return_heap = make_heap(key);
        meld(heap, return_heap);
        return return_heap;
    }
    void erase(MeldableHeapNode<_Key, _Compare> *key_heap){
        cut_path(key_heap);
        key_heap->erase(key_heap->get_key());
        compress_path(key_heap);
    }
    const _Key& find_min(MeldableHeapNode<_Key, _Compare> *heap){
        assert(heap->is_root() && !heap->empty());
        return heap->find_min();
    }
    MeldableHeapNode<_Key, _Compare> *meld(MeldableHeapNode<_Key, _Compare> *heap1,
                                            MeldableHeapNode<_Key, _Compare> *heap2){
        assert(heap1->is_root() && heap2->is_root());
        if(heap1->get_rank() < heap2->get_rank()) swap(heap1, heap2);
        hang(heap2, heap1);
        if(heap1->get_rank() == heap2->get_rank()) ++heap1->get_rank();
        return heap1;
    }
    MeldableHeapNode<_Key, _Compare> *find_root(MeldableHeapNode<_Key, _Compare> *heap){
        cut_path(heap);
        compress_path(heap);
    }
};

struct edge
{
    int to, id, cost;
    edge(const int _to, const int _id, const int _cost)
        : to(_to), id(_id), cost(_cost){}
    bool operator<(const edge& another) const {
        return cost > another.cost;
    }
};

struct eda
{
    int from, to, cost;
    eda(){}
    eda(const int _from, const int _to, const int _cost)
        : from(_from), to(_to), cost(_cost){}
};

vector<edge> G[MAX_N], tree[MAX_N];
eda es[MAX_M];
ll ans[MAX_M], base_ans;
int visit[MAX_N], in[MAX_N], n, m;

bool prim()
{
    priority_queue<edge> que;
    rep(i,n) visit[i] = numeric_limits<int>::max();
    visit[0] = -1;
    for(const edge& e : G[0]){
        visit[e.to] = e.cost;
        que.push((edge){e.to, e.id, e.cost});
    }
    while(!que.empty()){
        const edge p = que.top();
        que.pop();
        const int v = p.to;
        if(p.cost > visit[v]) continue;
        visit[v] = -1;
        tree[es[p.id].from].pb((edge){es[p.id].to, p.id, p.cost});
        tree[es[p.id].to].pb((edge){es[p.id].from, p.id, p.cost});
        base_ans += p.cost;
        for(const edge& e : G[v]){
            if(visit[e.to] > e.cost){
                visit[e.to] = e.cost;
                que.push((edge){e.to, e.id, e.cost});
            }
        }
    }
    return (*max_element(visit, visit + n) < 0);
}

struct info {
    int to, cost, id;
    info(const int _to, const int _cost, const int _id)
        : to(_to), cost(_cost), id(_id){}
    bool operator< (const info& another) const {
        return (cost == another.cost) ? (id < another.id) : (cost < another.cost);
    }
};

MeldableHeaps<info> mh;
MeldableHeapNode<info>* mhn[2 * MAX_M];

MeldableHeapNode<info>* dfs(int u, int p, int& id)
{
    in[u] = id++;
    MeldableHeapNode<info> *tmp = nullptr;
    for(const edge& e : tree[u]){
        if(!in[e.to]){
            MeldableHeapNode<info>* res = dfs(e.to, u, id);
            if(res){
                while(!res->empty()){
                    const info p = res->find_min();
                    if(in[p.to] < in[e.to]){
                        ans[e.id] = base_ans + (p.cost - e.cost);
                        break;
                    }
                    mh.erase(mhn[p.id]);
                }
                if(res->empty()) ans[e.id] = -1;
                if(tmp) tmp = mh.meld(tmp, res);
                else tmp = res;
            }else{
                ans[e.id] = -1;
            }
        }
    }
    for(const edge& e : G[u]){
        if(in[e.to] < in[u] && e.to != p){
            mhn[2 * e.id + (u < e.to)] = mh.make_heap((info){e.to, (int)e.cost, 2 * e.id + (u < e.to)});
            if(tmp) tmp = mh.meld(tmp, mhn[2 * e.id + (u < e.to)]);
            else tmp = mhn[2 * e.id + (u < e.to)];
        }
    }
    return tmp;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a, --b;
        if(a > b) swap(a, b);
        G[a].pb((edge){b, i, c}), G[b].pb((edge){a, i, c});
        es[i] = (eda){a, b, c}, ans[i] = -2;
    }
    if(!prim()){
        rep(i,m){
            cout << "-1\n";
        }
        return 0;
    }
    int id = 1;
    dfs(0, -1, id);
    rep(i,m){
        cout << ((ans[i] == -2) ? base_ans : ans[i]) << "\n";
    }
    return 0;
}
