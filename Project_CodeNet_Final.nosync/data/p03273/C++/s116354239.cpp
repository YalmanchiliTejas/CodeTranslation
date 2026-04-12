#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll h,w; cin>>h>>w;
    vector<string> a(h);
    rep(i,h) cin>>a[i];
    vector<ll> row(h,0), column(w,0);
    rep(i,h){
        bool ifwhite=true;
        rep(j,w){
            if(a[i][j]=='#') ifwhite=false;
        }
        if(ifwhite) row[i]=1;
    }

    rep(j,w){
        bool ifwhite=true;
        rep(i,h){
            if(a[i][j]=='#') ifwhite=false;
        }
        if(ifwhite) column[j]=1;
    }

    rep(i,h){
        if(row[i]==1) continue;
        rep(j,w){
            if(column[j]==1) continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}