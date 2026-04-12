/*
          , -- 、
        /;;;;;;', 　　　
        i二二二i
      , ' 　    ヽ ???
     i　ﾉﾉﾉﾉﾉﾍ .', 　　
     〉ﾘi' ﾟ ヮﾟﾉﾚく　 WAyon..........
  ○⊂}〈lﾄ--ｲl〉{つ● 　　
      ,ｒ/ー i-ヽヽ 　　　
     ｀｀i_ﾗi_ﾗ
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
const int INF=(int)1e12;
const int mod=(int)1e9+7;
#define all(a) (a).begin(),(a).end()
typedef vector<vector<int>> graph;

#define pb push_back

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

int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}



signed main () {
    int n;cin >>n;
    cout <<(n>=30?"Yes":"No")<<endl;
}



