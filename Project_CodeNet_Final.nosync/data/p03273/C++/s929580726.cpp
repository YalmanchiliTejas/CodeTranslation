#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int h,w;
    cin >>h>>w;
    vector<vector<char>> c(h,vector<char> (w,'.'));
    vector<bool> X(h,true);
    vector<bool> Y(w,true);
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
            if(c[i][j]=='#'){
                X[j]=false;
                Y[i]=false;
                //trueの時には書かない  
            }
        }
    }
    bool all;
    rep(i,h){
        all=true;
        rep(j,w){
            if(X[j]||Y[i]){
                continue;
            }
            cout<<c[i][j];
            all = false;
        }
        if(!all){
        cout<<endl;
        }
    }
}