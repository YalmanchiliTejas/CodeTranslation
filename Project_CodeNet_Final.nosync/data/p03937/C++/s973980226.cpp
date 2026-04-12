#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W; cin>>H>>W;
    vector<vector<char>> V(H,vector<char>(W));
    int num=0;
    rep(h,0,H)rep(w,0,W) {cin>>V.at(h).at(w); if(V.at(h).at(w)=='#')num++;}

    pair<int,int> pos={0,0};
    string ans="Possible";
    while(pos!=make_pair(H-1,W-1)){
        num--;
        if(pos.first+1<H && V.at(pos.first+1).at(pos.second)=='#') pos.first++;
        else if(pos.second+1<W && V.at(pos.first).at(pos.second+1)=='#') pos.second++;
        else{ans="Impossible"; break;}
    }
    
    if(pos==make_pair(H-1,W-1)) num--;
    if(num>0) ans="Impossible";
    cout<<ans<<endl;
}