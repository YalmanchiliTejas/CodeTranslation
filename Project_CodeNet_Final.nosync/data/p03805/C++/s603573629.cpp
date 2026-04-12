#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = long long;
using P = std::tuple<int,int>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int N, M;
vector<int> G[20];
int dp[10][1<<10];

int rec(int v, int visited){
    visited |= 1 << v;
    if(visited == (1 << N) - 1){
        return 1;
    }
    if(dp[v][visited] != -1){return dp[v][visited];}

    int res = 0;
    for(int w : G[v]){
        if(visited >> w & 1){continue;}

        res += rec(w, visited);
    }

    return dp[v][visited] = res;
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    for(int i=0;i<M;++i){
        int a, b;
        std::cin >> a >> b;

        --a; --b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    memset(dp, -1, sizeof(dp));
    
    int res = rec(0, 0);
    std::cout << res << std::endl;
}
