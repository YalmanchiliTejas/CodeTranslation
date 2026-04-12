#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n,vector<int>(n,0));
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        graph.at(a-1).at(b-1)=1;
        graph.at(b-1).at(a-1)=1;
    }

    vector<int> perm(n-1);
    iota(perm.begin(),perm.end(),1);
    
    int path=0;
    do{
        int index=0,now_node=0;
        while(index<n-1){
            int next_node=perm.at(index);
            if(!graph.at(now_node).at(next_node)) break;
            index++;
            if(index>=n-1) path++;
            now_node=next_node;
        }
    }while(next_permutation(perm.begin(),perm.end()));

    cout<<path<<endl;
}