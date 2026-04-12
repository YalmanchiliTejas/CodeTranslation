#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 1000000007
#define INF 1000000007
#define MAXN 10
#define MAXM 1001
#define MAXP 1000001
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int N, M, cnt;
int V[MAXN], used[MAXN], E[MAXN][MAXN];

void dfs(int s){
    used[s] = 1;
    bool flag = true;
    for(int i = 0;i < N;i++){
        if(!used[i]) flag = false;
    }
    if(flag){
        cnt++;
    }
    for(int i = 0;i < N;i++){
        if(E[s][i] && !used[i]){
            dfs(i);
        } 
    }
    used[s] = 0;
    return;
}
int main(){
    cin >> N >> M;
    int s, t;
    for(int i = 0;i < M;i++){
        cin >> s >> t;
        E[s - 1][t - 1] = 1;
        E[t - 1][s - 1] = 1;
    }

    dfs(0);

    printf("%d\n", cnt);

    return 0;
}