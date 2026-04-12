#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
const ll MOD=1000000007;

int main(){
    int H,W;
    cin >> H >> W;
    vector<int> count(H+W-1);
    rep (i,H){
        rep(j,W){
            char x;
            cin >> x;
            if (x=='#'){
                count[i+j]++;
            }
        }
    }
    bool ans=true;
    rep (i,H+W-1){
        if (count[i]>1){
            ans=false;
        }
    }
    if (ans){
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}