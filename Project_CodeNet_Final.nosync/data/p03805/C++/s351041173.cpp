#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define R return
#define MEM(dp,i) memset(dp,i,sizeof(dp))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=(1ll<<60);
const int MX = 10;
int n,m,ans,adj[MX][MX],a[MX];
/*vector<int>v[MX];
void dfs(int x,int mask){
    if(mask+1==(1<<n)){ans++;R;}
    for(auto nxt:v[x]){
        if(mask&(1<<nxt)||vis[nxt])continue;
        vis[nxt]=1;
        dfs(nxt,mask|(1<<nxt));
        vis[nxt]=0;
    }
}*/
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)a[i]=i;
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        adj[a][b]=adj[b][a]=1;
    }
    do{
        if(a[0])continue;
        bool b=1;
        for(int i=0;i<n-1;i++){
            if(!adj[a[i]][a[i+1]])b=0;
        }
        if(b)ans++;
    }while(next_permutation(a,a+n));
    printf("%d\n",ans);
}
