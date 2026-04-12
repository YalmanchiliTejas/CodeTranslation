#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

char fi[110][110];
 
int main(){
    int h,w;
    cin>>h>>w;

    rep(i,h){
        rep(j,w){
            cin>>fi[i][j];
        }
    }

    vector<int> hh,ww;

    rep(i,h){
        bool ok=true;
        rep(j,w){
            if(fi[i][j]=='#') ok=false;
        }
        if(ok) hh.push_back(i);
    }
    rep(j,w){
        bool ok=true;
        rep(i,h){
            if(fi[i][j]=='#') ok=false;
        }
        if(ok) ww.push_back(j);
    }

    rep(i,h){
        bool ok1=false;
        rep(j,w){
            bool ok=true;
            rep(k,hh.size()){
                if(hh[k]==i) ok=false;
            }
            rep(l,ww.size()){
                if(ww[l]==j) ok=false;
            }
            if(ok){
                cout<<fi[i][j];
                ok1=true;
            }
        }
        if(ok1) cout<<endl;
    }
}