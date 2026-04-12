#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+5;
const int MD=998244353;
int a[N],f[N][N][3];
void add(int &x,int y) {
    x+=y;
    if(x>=MD) x-=MD;
}
int main() {
    //freopen("in.txt","r",stdin);
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    f[0][0][0]=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=s;j++) {
            add(f[i+1][j][0],f[i][j][0]);
            add(f[i+1][j][1],f[i][j][0]),add(f[i+1][j][1],f[i][j][1]);
            add(f[i+1][j][2],f[i][j][0]),add(f[i+1][j][2],f[i][j][1]),add(f[i+1][j][2],f[i][j][2]);
            if(j+a[i]<=s) {
                add(f[i+1][j+a[i]][1],f[i][j][0]),add(f[i+1][j+a[i]][1],f[i][j][1]);
                add(f[i+1][j+a[i]][2],f[i][j][0]),add(f[i+1][j+a[i]][2],f[i][j][1]);
            }
        }
    }
    printf("%d\n",f[n][s][2]);
    return 0;
}