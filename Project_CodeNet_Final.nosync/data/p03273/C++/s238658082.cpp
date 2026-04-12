#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> P;

int main(){
    int h,w;
    cin >> h >> w;
    char tmp[110];
    char c[110][110] = {};
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
        }
    }
    int b[110][110];
    char ans[110][110] = {};
    int x=0;
    rep(i,h){
        bool bl=false;
        rep(j,w){
            tmp[j]=c[i][j];
            if(tmp[j]=='#')bl=true;
        }
        if(bl==true){
            rep(k,w)b[x][k]=tmp[k];
            x++;
        }
    }
    int y=0;
    rep(i,w){
        bool bl=false;
        rep(j,h){
            tmp[j]=b[j][i];
            if(tmp[j]=='#')bl=true;
        }
        if(bl==true){
            rep(k,h)ans[k][y]=tmp[k];
            y++;
        }
    }
    rep(i,x){
        rep(j,y){
            cout << ans[i][j];
        }
        cout << endl;
    }
}