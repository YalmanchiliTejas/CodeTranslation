#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int h,w; cin>>h>>w;
    char c[h][w]; rep(i,h)rep(j,w) cin>>c[i][j];
    bool hh[h],ww[w];
    rep(i,h) hh[i]=1;
    rep(i,w) ww[i]=1;
    rep(i,h)rep(j,w){
        if(c[i][j]=='#') hh[i]=0;
    }
    rep(i,w)rep(j,h){
        if(c[j][i]=='#') ww[i]=0;
    }
    rep(i,h){
        bool flg=0;
        rep(j,w){
            if(hh[i]||ww[j]) continue;
            cout<<c[i][j];
            flg=1;
        }
        if(flg) cout<<endl;
    }
    return 0;
}
