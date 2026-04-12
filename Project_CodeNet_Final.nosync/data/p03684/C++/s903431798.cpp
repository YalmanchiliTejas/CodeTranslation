#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

struct UnionFind{
    vector<int> par, cnt;
    UnionFind(int NV){ 
        par.clear(); 
        cnt.resize(NV, 1); 
        rep(i, 0, NV) par.push_back(i);
    }
    void reset(){ 
        rep(i, 0, cnt.size()) cnt[i] = 1; 
        rep(i, 0, par.size()) par[i] = i; 
    }
    int operator[](int x) {
        if(par[x] == x){
            return x;
        }
        else{
            return par[x] = operator[](par[x]);
        }
    }
    void operator()(int x, int y) {
        x = operator[](x);
        y = operator[](y);
        if (x != y) {
            par[x] = y;
            cnt[y] += cnt[x];
        }
    }
};

int N;

int main(){
    cin >> N;
    vector<pair<int,int>> vx,vy;
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        vx.push_back(make_pair(x,i));
        vy.push_back(make_pair(y,i));
    }

    vector<tuple<int, int, int>> edges;
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    for(int i=0;i<N-1;i++){
        edges.push_back(make_tuple( vx[i + 1].first - vx[i].first, vx[i].second, vx[i + 1].second));
        edges.push_back(make_tuple( vy[i + 1].first - vy[i].first, vy[i].second, vy[i + 1].second));
    }

    sort(edges.begin(), edges.end());
    
    UnionFind uf(N);
    ll ans = 0;

    for (auto p : edges) {
        int x, y, c;
        tie(c, x, y) = p;
 
        if (uf[x] != uf[y]) {
            uf(x, y);
            ans += c;
        }
    }
    cout << ans << endl;
}