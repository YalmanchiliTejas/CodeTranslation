#include <bits/stdc++.h>
using namespace std;;
#define llong long long
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int n,m;
vector<int> graph[9];
bool used[9];
int dfs(int now, int cnt){
    int ans = 0;
    if(cnt == n){
        ans = 1;
    }else{
        for(int i=0; i<graph[now].size(); i++){
            if(used[graph[now][i]] == false){
                used[graph[now][i]] = true;
                ans += dfs(graph[now][i], cnt+1);
                //cout << graph[now].size() << endl;
                used[graph[now][i]] = false;
            }
        }
    }

    return ans;

}
int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1 ; i<9; i++){
        used[i]  = false;
    }
    used[1] = true;
    int ans = dfs(1, 1);

cout << ans << endl;


}