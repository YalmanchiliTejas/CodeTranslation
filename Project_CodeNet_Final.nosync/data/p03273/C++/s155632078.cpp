#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll h,w;cin >>h>>w;
    vector<vector<char>>a(h,vector<char>(w));
    vector<bool>hmemo(h,true);
    vector<bool>wmemo(w,true);
    for (int i = 0; i < h; ++i) {
        bool wflag=true;
        for (int j = 0; j < w; ++j) {
            cin >>a[i][j];
            if(a[i][j]=='#')wflag=false;
        }
        if(wflag)hmemo[i]=false;
    }
    for (int j = 0; j < w; ++j) {
        bool hflg=true;
        for (int i = 0; i < h; ++i) {
            if(a[i][j]=='#')hflg=false;
        }
        if(hflg)wmemo[j]=false;
    }
    for (int i = 0; i < h; ++i) {
        bool flg=true;
        for (int j = 0; j < w; ++j) {
            if(hmemo[i]&&wmemo[j]){
                cout <<a[i][j];
            }
            if(!hmemo[i]){
                flg=false;
            }
        }
        if(flg)cout <<endl;
    }
    return 0;
}