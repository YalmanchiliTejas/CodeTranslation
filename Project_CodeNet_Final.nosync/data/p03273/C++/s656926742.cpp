#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int h,w;
vector<vector<char>> a(110,vector<char>(110));

int main(){
    cin>>h>>w;
    rep(i,0,h) rep(j,0,w) cin>>a[i][j];

    rep(i,0,h){
        int cnt=0;
        rep(j,0,w){
            if(a[i][j]=='.') cnt++;
        }
        if(cnt==w){
            rep(j,0,w) a[i][j]='F';
        }
    }

    rep(i,0,w){
        int cnt=0;
        rep(j,0,h){
            if(a[j][i]=='.' || a[j][i]=='F') cnt++;
        }
        if(cnt==h){
            rep(j,0,h) a[j][i]='F';
        }
    }

    rep(i,0,h){
        int cnt=0;
        rep(j,0,w){
            if(a[i][j]!='F') cout<<a[i][j];
            else cnt++;
        }
        if(cnt!=w) cout<<"\n";
    }
    return 0;
}