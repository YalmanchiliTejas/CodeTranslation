#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int n,visited[8];
vector<int>adj[8];
int dfs(int i){
    visited[i]=1;
    int flag=1;
    for(int j=0;j<n;++j){
        if(!visited[j]){
            flag=0;
        }
    }
    if(flag){
        return 1;
    }
    int sum=0;
    for(auto x:adj[i]){
        if(!visited[x]){
            sum+=dfs(x);
            visited[x]=0;
        }
    }
    return sum;
}
int main()
{
int i,m;
scanf("%d %d",&n,&m);
while(m--){
    int u,v;
    scanf("%d %d",&u,&v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
printf("%d",dfs(0));



    return 0;
}
