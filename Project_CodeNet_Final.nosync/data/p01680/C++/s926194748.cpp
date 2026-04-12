#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
struct UnionFind {
    vector<int> data;
    int size;
    UnionFind(int N) : 
        data(N, -1), size(N) {}
    int root(int x){
        if(data[x] < 0) return x;
        return data[x] = root(data[x]);
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(-data[x] < -data[y]) swap(x, y);
        size--;
        data[x] += data[y];
        data[y] = x;
    }
};

const int MOD = 1000000007;

int main(){
    int N, M;
    while(cin >> N >> M && N > 0){
        UnionFind uf(N);
        REP(i, M){
            int a, b;
            cin >> a >> b;
            a--; b--;
            uf.unite(a, b);
        }
        int s = uf.size;
        int ans = 1;
        REP(i, s) ans = (2LL * ans) % MOD;
        if(s < N) {
            ans = (ans + 1) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}