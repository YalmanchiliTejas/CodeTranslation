#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    int h,w; cin>>h>>w;
    vector<string> a(h);
    rep(i,0,h) cin>>a[i];

    vector<bool> hcheck(h,1);
    vector<bool> wcheck(w,1);
    rep(i,0,h){
        bool ok=true;
        rep(j,0,w){
            if(a[i][j]=='#') ok=false;
        }
        if(ok) hcheck[i]=0;
    }

    rep(j,0,w){
        bool ok=true;
        rep(i,0,h){
            if(a[i][j]=='#') ok=false;
        }
        if(ok) wcheck[j]=0;
    }

    int H=0;
    int hsize=0;
    rep(i,0,h){
        if(hcheck[i]==1) hsize++;
    }
    vector<vector<char>> ans(hsize);
    rep(i,0,h){
        if(hcheck[i]==0) continue;
        rep(j,0,w){
            if(wcheck[j]==0) continue;
            ans[H].push_back(a[i][j]);
        }
        H++;
    }
    rep(i,0,ans.size()){
        rep(j,0,ans[i].size()){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

}