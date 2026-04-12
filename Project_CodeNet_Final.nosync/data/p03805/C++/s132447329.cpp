#include<bits/stdc++.h>

using namespace std;
int n,m;
vector<int> g[8];
int fun(int now,int bit){
    cerr<<" "<<now<<" "<<bitset<10>(bit)<<endl;
    int res=0;
    if(bit==(1<<n)-1)return 1;
    for(int i=0;i<g[now].size();i++){
        if(!(bit&(1<<g[now][i]))){
            res+=fun(g[now][i],bit|(1<<g[now][i]));
        }
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<fun(0,1)<<endl;
    return 0;
}