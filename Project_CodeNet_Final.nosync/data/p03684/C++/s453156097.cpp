#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>

using namespace std;

struct Union_find{
    vector<int> par;
    vector<int> rank;
    Union_find(int p){
        par = vector<int>(p + 1);
        rank = vector<int>(p + 1);
        for(int i = 1; i <= p; i++){
            par[i] = i;
        }
    }
    int find(int x){
        if(par[x] == x)
            return x;
        else{
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]){
            par[x] = y;
        } else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    int n;
    long long ans = 0;
    cin >> n;
    vector<pair<int, int>> x(n), y(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        x[i] = {a, i};
        y[i] = {b, i};
    }
    sort(begin(x), end(x));
    sort(begin(y), end(y));
    vector<tuple<int, int, int>> z(2 * n - 2);
    for(int i = 0; i < n - 1; i++){
        z[i] = make_tuple(x[i + 1].first - x[i].first, x[i].second, x[i + 1].second);
    }
    for(int i = 0; i < n - 1; i++){
        z[i + n - 1] = make_tuple(y[i + 1].first - y[i].first, y[i].second, y[i + 1].second);
    }
    sort(begin(z), end(z));
    Union_find uf(n);
    for(auto&& i : z){
        int a, b, c;
        tie(a, b, c) = i;
        if(!uf.same(b, c)){
            uf.unite(b, c);
            ans += a;
        }
    }
    cout << ans << endl;
    return 0;
}
