#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

//map<int,int> mmap;
int n,m,ret=0;
int cot[8][8];
int vis[10];
// n,r
void dfs(int v,int e_ct){
    if(e_ct==n-1){
        int tmp =0;
        for(int i=0;i<n;i++)
            tmp+=vis[i];
        if(tmp==n) ret++;
        return;
    }


    for(int i=0;i<n;i++){
        if(!vis[i] && cot[v][i]){
            vis[i]=1;
            //cout<< v<<" " <<i<< " "<<e_ct+1<<endl;
            dfs(i,e_ct+1);
            vis[i]=0;
        }
    }

}

int main(){

    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
            cin>>a>>b;
            a--;b--;
            cot[a][b]=1;
            cot[b][a]=1;
    }
    vis[0]=1;
    dfs(0,0);
    cout<<ret<<endl;
    return 0;
}
