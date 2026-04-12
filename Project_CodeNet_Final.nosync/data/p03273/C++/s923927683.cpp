#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll h,w;
    cin >> h >> w;
    vector<vector<char>>mp(h,vector<char>(w));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++) cin >> mp[i][j];
    }
    vector<ll>tate,yoko;
    for(ll i=0;i<h;i++){
        bool ok=true;
        for(ll j=0;j<w;j++){
            if(mp[i][j]=='#') ok=false;
        }
        if(ok){
            yoko.push_back(i);
        }
    }
    for(ll i=0;i<w;i++){
        bool ok=true;
        for(ll j=0;j<h;j++){
            if(mp[j][i]=='#') ok=false;
        }
        if(ok) tate.push_back(i);
    }
    for(ll i=0;i<h;i++){
        bool ok1=false;
        for(ll k=0;k<yoko.size();k++){
            if(i==yoko[k]) ok1=true;
        }
        if(ok1) continue;
        for(ll j=0;j<w;j++){
            bool ok=false;
            for(ll k=0;k<tate.size();k++){
                if(j==tate[k]) ok=true;
            }
            if(ok) continue;
            cout << mp[i][j];
        }
        cout << endl;
    }
}