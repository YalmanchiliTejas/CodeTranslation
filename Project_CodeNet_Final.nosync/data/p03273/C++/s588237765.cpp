#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    vector<string> g;
    cin>>h>>w;
    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        g.emplace_back(s);
    }
    for (int i = 0; i < h; ++i) {
        bool f=true;
        for (auto j:g[i]){
            if(j=='#')f=false;
        }
        if(f){
            for (int j = 0; j < w; ++j) {
                g[i][j]='!';
            }
        }
    }
    for (int i = 0; i < w; ++i) {
        bool f=true;
        for (int j = 0; j < h; ++j) {
            if(g[j][i]=='#')f=false;
        }
        if(f){
            for (int j = 0; j < h; ++j) {
                g[j][i]='!';
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        bool f=false;
        for (int j = 0; j < w; ++j) {
            if(g[i][j]=='!')continue;
            cout<<g[i][j];
            f=true;
        }
        if(f)cout<<endl;
    }
    return 0;
}