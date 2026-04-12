#include<iostream>
#include<vector>
using namespace std;

void solve(short dep,short n,int& ans,short node,bool *f,vector<short>* edge){
    if(dep==n){
        ans++;
        return;
    }
    f[node]=true;
    short l=edge[node].size();
    for(short i=0;i<l;i++){
        short j=edge[node][i];
        if(!f[j]){
            solve(dep+1,n,ans,j,f,edge);
        }
    }
    f[node]=false;
}

int main(){
    short n,m;
    while(cin>>n>>m){
        vector<short>edge[9];
        bool f[9]={0};
        int ans=0;
        while(m--){
            short x,y;
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        solve(1,n,ans,1,f,edge);
        cout<<ans<<endl;
    }
    return 0;
}
