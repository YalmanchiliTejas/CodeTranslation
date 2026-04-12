/*
      author  : nishi5451
      created : 14.08.2020 20:03:48
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,w;
    cin >> h >> w;
    vector<bool> y(h,true),x(w,true);
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    rep(i,h){
        rep(j,w){
            if(a[i][j]!='.') y[i]=false;
        }
    }
    rep(i,w){
        rep(j,h){
            if(a[j][i]!='.') x[i]=false;
        }
    }
    rep(i,h){
        rep(j,w){
            if(y[i] || x[j]) continue;
            cout << a[i][j];
        }
        if(!y[i])
            cout << endl;
    }

    return 0;
}