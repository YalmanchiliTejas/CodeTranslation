#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define mod 1000000007


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



int gcd(int a, int b){
    while(b){
        int t = a;
        a = b;
        b = t%b;
    }
    return a;
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}


vector<ll> S;
vector<ll> P;

ll solve(ll i, ll k){
//    cout << i << " " << k << endl;
//    if(i==0){
//        if(k==0) return 0;
//        else return 1;
//    }
    if(k==1){
        if(i==0) return 1;
        else return 0;
    }
    else if(k<S[i-1]+2) return solve(i-1, k-1);
    else if(k==S[i-1]+2) return P[i-1] + 1;
    else if(k<=2 * S[i-1]+2) return P[i-1] + 1 + solve(i-1, k - S[i-1] - 2);
    return 2 * P[i-1] + 1;
}


int main() {
    ll N, K; cin >> N >> K;
    S.resize(N+1);
    P.resize(N+1);
    S[0] = 1;
    P[0] = 1;
    for(int i=0; i<N; i++){
        S[i+1] = 2 * S[i] + 3;
    }
    
    for(int i=0; i<N; i++){
        P[i+1] = 2 * P[i] + 1;
    }

    
    cout << solve(N, K) << endl;
    return 0;
}
