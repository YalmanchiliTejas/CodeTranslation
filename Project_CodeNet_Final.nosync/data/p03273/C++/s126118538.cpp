#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int n,m;
int f[N][N];
char a[N][N];
int main() {
    scanf("%d%d",&n,&m);
    getchar();
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            scanf("%c",&a[i][j]);
        }
        getchar();
    }
    for (int i=1;i<=n;i++) {
        bool flag=true;
        for (int j=1;j<=m;j++) {
            if (a[i][j]=='#') {
                flag=false;
                break;
            }
        }
        if (flag) {
            for (int j=1;j<=m;j++) f[i][j]=1;
        }
    }
    for (int i=1;i<=m;i++) {
        bool flag=true;
        for (int j=1;j<=n;j++) {
            if (a[j][i]=='#') {
                flag=false;
                break;
            }
        }
        if (flag) {
            for (int j=1;j<=n;j++) f[j][i]=1;
        }
    }
    for (int i=1;i<=n;i++) {
        bool flag=false;
        for (int j=1;j<=m;j++) {
            if (f[i][j]==0) {
                printf("%c",a[i][j]);
                flag=true;
            }
        }
        if (flag) printf("\n");
    }
    return 0;
}