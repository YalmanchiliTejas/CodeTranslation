#include<bits/stdc++.h>
using namespace std;
#define rep(q,w,e) for(int q=(w);q<=e;q++)
const int N=105;
int n,m;
char a[N][N];
bool s[N],t[N];
int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",a[i]+1);
    rep(i,1,n) rep(j,1,m) {
        if (a[i][j]=='#') {
            s[i]=true; break;
        }
    }
    rep(j,1,m) rep(i,1,n) {
        if (a[i][j]=='#') {
            t[j]=true; break;
        }
    }
    rep(i,1,n) {
        bool bo=false;
        rep(j,1,m) {
            if (!s[i] || !t[j]) continue;
            printf("%c",a[i][j]);
            bo=true;
        }
        if (bo) printf("\n");
    }
    return 0;
}