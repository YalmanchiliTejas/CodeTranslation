#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
class UnionFind{
    public:
        ll size;
        ll *rank;
        ll *parent;

        UnionFind(ll N){
            this->size = N;
            rank = new ll[size];
            parent = new ll[size];
            for(ll i = 0; i < size; ++i){
                rank[i] = 0;
                parent[i] = i;
            }
        }

        ~UnionFind(){
        }

        ll find(ll child){
            return (child == parent[child] ? child : parent[child] = find(parent[child]));
        }

        void unit(ll x, ll y){
            x = find(x); y = find(y);
            if(x != y){
                if(rank[x] > rank[y]){
                    parent[y] = x;
                }else{
                    parent[x] = y;
                    if(rank[x] == rank[y]){
                        ++rank[y];
                    }
                }
            }
        }

        bool same(ll x, ll y){
            return (find(x) == find(y));
        }

};
struct V{
    ll x, y, i;
};
struct E{
    ll d, i, j;
};
int main(){
    ll N;
    cin >> N;
    vector<V> v(N);
    for(ll i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        v[i] = V{x, y, i};
    }
    vector<E> e;
    sort(v.begin(), v.end(), [&](V a, V b){return a.x < b.x;});
    for(ll i = 0; i < N - 1; i++) e.push_back(E{v[i + 1].x - v[i].x, v[i].i, v[i + 1].i});
    sort(v.begin(), v.end(), [&](V a, V b){return a.y < b.y;});
    for(ll i = 0; i < N - 1; i++) e.push_back(E{v[i + 1].y - v[i].y, v[i].i, v[i + 1].i});
    UnionFind U(N);
    ll ans = 0;
    sort(e.begin(), e.end(), [&](E a, E b){return a.d < b.d;});
    for(auto u : e){
        if(U.same(u.i, u.j)) continue;
        U.unit(u.i, u.j);
        ans += u.d;
    }
    cout << ans << endl;
    return 0;
}
