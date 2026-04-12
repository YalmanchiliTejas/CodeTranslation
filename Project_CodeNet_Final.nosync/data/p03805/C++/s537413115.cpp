#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int MOD = 1000000007;
int flag[8];
int graph[8][8],N,M,cnt;
void dfs(int next){
    for(int i = 0;i < N;i++){
        if(graph[next][i] && !flag[i]){
            flag[i] = 1;
            dfs(i);
            flag[i] = 0;
        }
    }
    for(int i = 0;i < N;i++){
        if(flag[i] == 0)return;
    }
    cnt++;//flagが全部１の場合
}
main(){
    cin >> N >> M;
    for(int i = 0;i < M;i++){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }
    flag[0] = 1;
    dfs(0);
    cout << cnt << endl;
}