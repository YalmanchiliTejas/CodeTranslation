#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;
int Count=0;
vector<vector<int>> gragh;
vector<int> reg;
int n;
void dfs(int x){
   // cout<<x<<endl;
   reg[1]=1;
    bool h=true;
    for(int i=1;i<=n;i++){
        if(reg[i]==0){
            h=false;
        }
    }
             //   cout<<gragh[x].size()<<endl;

    if(h){
        Count++;
        return;
    }else{
        for(int i=0;i<gragh[x].size();i++){
            
            if(reg[gragh[x][i]]==0){
                reg[gragh[x][i]]=1;
              //  cout<<"from"<<x<<"to"<<gragh[x][i]<<endl;
                dfs(gragh[x][i]);
                reg[gragh[x][i]]=0;
            }
        }
    }
    return;
}
int main(){
    int m;
    cin >> n >> m;
    gragh.resize(n+2);
    reg.resize(n+2);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        gragh[x].push_back(y);
      //  cout<<"njkd"<<endl;
        gragh[y].push_back(x);
        
    }
    
    dfs(1);reg[1]=1;
    cout<<Count<<endl;
}