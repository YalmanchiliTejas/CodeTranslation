#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <limits>
using ll = long long;
using ld = long double;
int MOD = 1e9 + 7;
using namespace std;
struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return;   //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    deque<int> de;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if(i%2==0){
            de.push_back(x);
        }else{
            de.push_front(x);
        }
    }
    if(n%2==0){
        for (int i = 0; i < n;i++){
            cout << de[i]<<" " ;
        }
    }else{
        for (int i = n - 1; i >= 0;i--){
            cout << de[i] <<" ";
        }
    }
    cout << endl;
}