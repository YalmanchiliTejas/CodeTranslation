#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL<<60;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

class UnionFind{
public:
    // 親の番号を格納する
    // Parent -> -(the size)
    vector<int> Parent;
    
    // initialization
    // all nodes are roots
    UnionFind(int N){
        Parent =  vector<int>(N, -1);
    }
    
    int root(int A){
        if (Parent[A] < 0) return A; // A is in its own group.
        return Parent[A] = root(Parent[A]); // exchange parents
    }
    
    long long size(int A){
        return -Parent[root(A)];
    } 
    
    void connect(int A, int B){
        A = root(A);
        B = root(B);
        
        if (A == B) return; //already connected
        if (size(A) < size(B)) swap(A, B);
        
        Parent[A] += Parent[B]; //小さい方を大きい方にくっつける
        Parent[B] = A; //小さい方を大きい方にくっつける
    }
};
 
 
int main(){
    int N;
    cin >> N;
    
    vector<int> x(N),y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    
    using pint = pair<int, int>; //edgeを表現する
    using Edge = pair<long long, pint>; 
    vector<Edge> edges;
    
     // x 軸方向にソートして隣接している部分のみ
    vector<int> ids(N);
    iota(ids.begin(), ids.end(), 0); //???????
    sort(ids.begin(), ids.end(), [&](int i, int j) {return x[i] < x[j];});
    
    for (int i = 0; i+1 < ids.size(); i++){
        int u = ids[i];
        int v = ids[i+1];
        edges.push_back( Edge(x[v] - x[u], pint(u, v) ) );
    }
    
     // y軸方向にソートして隣接している部分のみ考える
    sort(ids.begin(), ids.end(), [&](int i, int j) {return y[i] < y[j]; } );
    for (int i = 0; i+1 < ids.size(); i++){
        int u = ids[i];
        int v = ids[i+1];
        edges.push_back( Edge(y[v] - y[u], pint(u, v)) );
    }
    
    sort(edges.begin(), edges.end()); //edge.costが小さい順にソートする
    UnionFind Uni(N);
    long long res = 0;
    
    for (auto e : edges){
        long long cost = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if(Uni.root(u) == Uni.root(v)) continue;
        Uni.connect(u, v);
        res += cost;
    }
    
    cout << res << endl;
}