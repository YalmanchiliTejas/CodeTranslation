#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

class UnionFind{
public:
    //親の番号を格納する。親だった場合はー（その集合のサイズ）
    vector<int> parents;

    //作る時はparentsを-1で初期化する
    //こうすることで全部ばらばらになる
    UnionFind(int n){
        parents = vector<int>(n, -1);
    }

    //Aがどのグループにいるか調べる
    int root(int A){
        if(parents[A]<0) return A;
        return parents[A] = root(parents[A]);
    }

    //自分のいるグループの大きさを調べる
    int size(int A){
        return -parents[root(A)];
    }

    //AとBをくっつける
    bool connect(int A, int B){
        //AとBを直接ではなく親同士をくっつける
        A=root(A);
        B=root(B);
        if(A==B){
            return false;
        }

        //大きい方（A)に小さい方（B)をくっつけたい
        if(size(A)<size(B)) swap(A, B);

        parents[A] += parents[B];
        parents[B] = A;

        return true;
    }
};


class Edge {
    public:
    int source, target;
    ll cost;
    Edge(int source=0, int target=0, ll cost=0):
    source(source), target(target), cost(cost){}
    bool operator < (const Edge &e) const{
        return cost < e.cost;
    }
};

int kruskal(int N, vector<Edge> edges){
    ll totalCost = 0;
    sort(edges.begin(), edges.end());

    UnionFind uni(N);
    for(int i=0; i<edges.size(); i++){
        Edge e=edges[i];
        if(uni.root(e.source) != uni.root(e.target)){
            totalCost += e.cost;
            uni.connect(e.source, e.target);
        }
    }

    return totalCost;
}

typedef tuple<ll, ll, int> T;

int main(){
    int N; cin >> N;
    vector<T> xy(N), yx(N);
    for(int i=0; i<N; ++i){
        ll x, y; cin >> x >> y;
        xy[i] = make_tuple(x, y, i);
        yx[i] = make_tuple(y, x, i);
    }

    sort(xy.begin(), xy.end());
    sort(yx.begin(), yx.end());

    vector<Edge> edges;
    for(int i=1; i<N; ++i){
        ll x1, y1, x2, y2; int id1, id2;
        tie(x1, y1, id1) = xy[i];
        tie(x2, y2, id2) = xy[i-1];
        edges.push_back(Edge(id2, id1, abs(x1-x2)));

        tie(y1, y2, id1) = yx[i];
        tie(y2, x2, id2) = yx[i-1];
        edges.push_back(Edge(id2, id1, abs(y1-y2)));
    }

    cout << kruskal(N, edges) << endl;

    return 0;
}