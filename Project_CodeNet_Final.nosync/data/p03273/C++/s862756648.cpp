//107 B - Grid Compression 2018/08/25
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int h , w; cin >> h >> w;
    string a[h];
    int counter=0;
    rep(i, h) cin >> a[i];
    rep(i ,h){
        rep(j ,w){
            if(a[i][j]=='#') continue;
            ++counter;
        }
        if(counter==a[i].size()){
            rep(k ,w) a[i][k]='0';
        }
        counter = 0;
    }
    counter = 0;
    rep(i ,w){
        rep(j ,h){
            if(a[j][i]=='#') continue;
            ++counter;
        }
        if(counter==h){
            rep(j ,h) a[j][i]='0';
        }
        counter = 0;
    }
    counter = 0;
    rep(i ,h){
        rep(j , w){
            if(a[i][j]=='0') continue;
            else cout << a[i][j];
        }
        rep(k ,w){
            if(a[i][k]=='0') ++counter;
        }
        if (counter==w) {}
        else cout << endl;
        counter = 0;
        }
}