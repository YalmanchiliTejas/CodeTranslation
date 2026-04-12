#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    vector<vector<char>> a(110,vector<char>(110));
    int h,w;
    cin >> h  >> w;
    rep(i,h) rep(j,w) cin >> a[i][j];
    vector<bool> hh(110,1),ww(110,1);
    //x
    rep(i,h){
        bool ok = 1;
        rep(j,w) if(a[i][j]=='#') ok = 0;
        if(ok) hh[i]=0;
    }
    rep(j,w){
        bool ok = 1;
        rep(i,h) if(a[i][j]=='#') ok = 0;
        if(ok) ww[j]=0;
    }
    rep(i,h){
        rep(j,w) if(hh[i]==1 && ww[j]==1){
            cout<<a[i][j];
        }
        if(hh[i]) cout<<endl;
    }    
    return 0;
}