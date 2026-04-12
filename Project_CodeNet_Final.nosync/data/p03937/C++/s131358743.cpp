#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define int long long
#define P pair<long,long>
#define all(a) a.begin(),a.end()
using namespace std;

vector<string> grid;
    int h,w;

bool dfs(int x, int y){
    if(x==h-1 and y==w-1) return true;
    if(x+1<h){ if(grid.at(x+1).at(y)=='#') return dfs(x+1,y); }
    if(y+1<w){ if(grid.at(x).at(y+1)=='#') return dfs(x,y+1); }
    return false;
}


signed main(){
    cin>>h>>w;
    int cnt=0;
    rep(i,h){
        grid.push_back("");
        cin>>grid.at(i);
        rep(j,w){
            if(grid.at(i).at(j)=='#') cnt++;
        }
    }
    cout<<((dfs(0,0) and cnt==h+w-1)?"Possible":"Impossible")<<endl;
}