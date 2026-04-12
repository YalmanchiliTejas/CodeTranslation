#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int N, M;
vector<vector<int>> edge(9);
int goal = 0, ans = 0;
bitset<9> used;

void rec(int corrent = 1){
    if(corrent == goal){
        if(used.count() == N) ++ans;
        return;
    }
    for(auto next : edge[corrent]){
        if(used[next]) continue;
        used[next] = true;
        rec(next);
        used[next] = false;
    }
    return;
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b; scanf("%d %d", &a, &b);
        edge[a].push_back(b), edge[b].push_back(a);
    }
    
    for(int i = 2; i <= N; ++i){
        used.reset();
        used[1] = true;
        goal = i;
        rec();
    }
    printf("%d\n", ans);
    
    return 0;
}