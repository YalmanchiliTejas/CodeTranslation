#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

char fi[110][110];
bool ng[110][110];

int main(){
    int h,w;
    cin>>h>>w;
    
    rep(i,h) rep(j,w) cin>>fi[i][j];
    map<int,int> mh,mw;
    rep(i,h){
        bool ok=true;
        rep(j,w){
            if(fi[i][j]=='#') ok=false;
        }
        if(ok){
            rep(j,w) ng[i][j]=true;
        }
    }

    rep(j,w){
        bool ok=true;
        rep(i,h){
            if(fi[i][j]=='#') ok=false;
        }
        if(ok){
            rep(i,h) ng[i][j]=true;
        }
    }

    rep(i,h){
        bool ok1=false;
        rep(j,w){
            if(!ng[i][j]){
                cout<<fi[i][j];
                ok1=true;
            }
        }
        if(ok1) cout<<endl;
    }
}