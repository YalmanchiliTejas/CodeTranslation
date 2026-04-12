#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define inf 1001001001
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(void) {
    int h, w; cin >> h >> w;
    char a[101][101];
    bool yoko[h], tate[w];
    rep(i, h) yoko[i] = false;
    rep(j, w) tate[j] = false;
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            if(a[i][j] == '#')
                yoko[i]=true, tate[j]=true;
        }
    }
    rep(i, h) {
        if(!yoko[i]) continue;
        rep(j, w) {
            if(!tate[j]) continue;
            printf("%c",a[i][j]);
        }puts("");
    }
}
