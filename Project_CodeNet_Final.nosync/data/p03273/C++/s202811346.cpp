#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

int main(){
    int h,w; cin>>h>>w;
    vector<string> s;
    rep(i,h){
        string x; cin>>x;
        bool flg=0;
        rep(i,w){
            if(x[i]=='#') flg=1;
        }
        if(flg) s.push_back(x);
    }
    rep(i,w){
        bool flg=1;
        for(auto j:s){
            // cout<<j<<endl;
            if(j[i]=='#') flg=0;
        }
        if(flg){
            // cout<<1<<endl;
            for(auto &j:s){
                // cout<<j[i]<<endl;
                j[i]='x';
            }
        }
    }
    // for(auto i:s) cout<<i<<endl;
    for(auto i:s){
        rep(j,w){
            if(i[j]!='x') cout<<i[j];
        }
        cout<<endl;
    }
    return 0;
}
