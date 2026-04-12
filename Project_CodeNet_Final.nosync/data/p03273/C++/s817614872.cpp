#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int H,W;
    cin>>H>>W;
    vector<string> map(H,"");
    vector<int> era;
    REP(i,H)cin>>map[i];
    for(int i=H-1;i>=0;i--){
        if(map[i].find("#")==string::npos)map.erase(map.begin()+i);
    }
    REP(i,W){
        bool is=false;
        REP(y,map.size())if(map[y][i]=='#')is=true;
        if(!is)era.push_back(i);
    }
    REP(i,map.size()){
        REP(y,W){
            if(find(era.begin(),era.end(),y)==era.end())cout<<map[i][y];
        }
        cout<<endl;
    }
}