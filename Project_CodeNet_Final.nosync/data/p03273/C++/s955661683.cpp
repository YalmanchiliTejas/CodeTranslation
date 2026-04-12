#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int H,W;
    cin >> H >> W;
    vector<string> V(H);
    rep(i,0,H)cin >> V[i];
    rep(i,0,H){
        int cnt = 0;
        rep(j,0,W)if(V[i][j] == '#')cnt++;
        if(cnt == 0)rep(j,0,W)V[i][j] = '-';
    }
    rep(j,0,W){
        int cnt = 0;
        rep(i,0,H)if(V[i][j] == '#')cnt++;
        if(cnt == 0)rep(i,0,H)V[i][j] = '-';
    }
    rep(i,0,H){
        int cnt = 0;
        rep(j,0,W){
            if(V[i][j] == '-' || V[i][j] == '\n')continue;
            cnt++;
            cout << V[i][j];
        }
        if(cnt)cout << endl;
    }
    
}