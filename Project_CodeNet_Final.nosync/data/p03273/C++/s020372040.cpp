#include<bits/stdc++.h>
//CLOCKS_PER_SEC
#define se second
#define fi first
#define ll long long
#define Pii pair<int,int>
#define Pli pair<ll,int>
#define ull unsigned long long
#define pb push_back
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const double Pi=3.14159265;
const int N=4e5+10;
const ull base=163;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
char s[200][200];
bool vis[200][200];
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i){
        int tot=0;
        for(int j=1;j<=m;++j){
            if(s[i][j]=='.')tot++;
        }
        if(tot==m)for(int j=1;j<=m;++j)vis[i][j]=1;
    }
    for(int i=1;i<=m;++i){
        int tot=0;
        for(int j=1;j<=n;++j){
            if(s[j][i]=='.')tot++;
        }
        if(tot==n)for(int j=1;j<=n;++j)vis[j][i]=1;
    }
    for(int i=1;i<=n;++i){
            int p=0;
        for(int j=1;j<=m;++j){
            if(!vis[i][j])cout<<s[i][j],p=1;
        }
    if(p)
        cout<<endl;
    }
    return 0;
}

