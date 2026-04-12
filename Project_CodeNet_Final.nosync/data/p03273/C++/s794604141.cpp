#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int H,W;
string fld[111];

signed main(){
    cin>>H>>W;
    rep(i,H)cin>>fld[i];

    vector<int>xs,ys;
    rep(i,H)rep(j,W)if(fld[i][j]=='#'){
        xs.pb(j);ys.pb(i);
    }
    sort(all(xs));sort(all(ys));
    xs.erase(unique(all(xs)),xs.end());
    ys.erase(unique(all(ys)),ys.end());

    for(auto y:ys){
        for(auto x:xs){
            cout<<fld[y][x];
        }cout<<endl;
    }
    return 0;
}
