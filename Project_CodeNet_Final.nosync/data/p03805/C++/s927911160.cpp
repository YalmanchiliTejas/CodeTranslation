#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
template<class T> inline void chmin(T &a, T b){if(a>=b)a=b;}
template<class T> inline void chmax(T &a, T b){if(a<=b)a=b;}
typedef long long ll;

int N,M;
vector<vector<int> > G;
// dp[bit][v] : 訪れた頂点がbitのときのvへの道筋の数
int dp[1<<8][8];

int rec(int bit = 1,int v = 0){
    // 全部調査ずみなら
    if(bit == (1<<N)-1) return 1;
    // 行く先が全部調査済みなら行ける場所がないので１を返す
    if(dp[bit][v]) return dp[bit][v];

    int ret = 0; // 全部の頂点に行けない場合は0が帰る。
    for(auto nv : G[v]){
        if(bit & (1<<nv)) continue; // nvは調査ずみ
        // その頂点を調査済みにして一つ下の深さへ
        ret += rec(bit | (1<<nv), nv);
    }
    return dp[bit][v] = ret;
}

int main()
{
    cin >> N >> M;
    G.assign(N,vector<int>());
    REP(i,M){
        int from,to;
        cin >> from >> to;
        from--;to--;
        G[from].push_back(to);
        G[to].push_back(from);
    }
    
    cout << rec() << endl;
    return 0;
}