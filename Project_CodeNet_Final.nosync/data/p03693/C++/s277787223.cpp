#include<bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#define ll long long
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)

const ll MOD = 1e9+7;

// Combinationの使い方
// vector<vector<ll>> v(N+1, vector<ll>(N+1, 0));
// comb(v);
void comb(vector<vector<ll>> &v){
    for(int i = 0; i < v.size(); i++){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for(int k = 1; k < v.size(); k++){
        for(int j = 1; j < k; j++){
            v[k][j] = (v[k-1][j-1] + v[k-1][j]);
            //余りを求める問題は毎回計算ごとにやる
            // v[k][j] = (v[k-1][j-1] + v[k-1][j]) % MOD;
        }
    }
}

// Union Find
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

// vector<tuple<long,long>> items; // (value, weight)
// auto item = items[i];
// long v = get<0>(item);
// long w = get<1>(item);
// long v, w;
//   for( int i = 0; i < N; i++ ){
//     cin >> v >> w;
//     items.push_back( make_tuple(v, w) ); // item : (value, weight)
//   }

// 1 << 3 : int "3" change to bit "100"
// rep(pattern, 1 << N) if (pattern & (1 << x)) cnt++

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    if((r*100+g*10+b) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}