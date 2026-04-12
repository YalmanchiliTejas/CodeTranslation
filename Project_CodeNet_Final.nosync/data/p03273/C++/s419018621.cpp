#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,h)cin>>s[i];
    rep(i,h){
        bool ng=true;
        rep(j,w){
            if(s[i][j]=='#')ng=false;
        }
        if(ng){
            rep(j,w)s[i][j]='0';
        }
    }
    rep(i,w){
        bool ng=true;
        rep(j,h){
            if(s[j][i]=='#')ng=false;
        }
        if(ng){
            rep(j,h)s[j][i]='0';
        }
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j]!='0')cout<<s[i][j];
        }
        bool ng=true;
        rep(j,w){
            if(s[i][j]!='0')ng=false;
        }
        if(!ng)cout<<endl;
    }
    return 0;
}