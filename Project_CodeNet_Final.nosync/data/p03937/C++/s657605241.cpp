#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=10;
typedef pair<int,int> pii;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
char gc() {
    char ch=getchar();
    while(ch!='.'&&ch!='#') ch=getchar();
    return ch;
}
int n,m,f[N*N],dx[5]={0,1,0,0,-1},dy[5]={0,0,1,-1,0};
char a[N][N];
int getf(int x) { return x==f[x]?x:f[x]=getf(f[x]); }
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j]=gc();
    if(a[1][1]!='#'||a[n][m]!='#') return puts("Impossible"),0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) f[(i-1)*m+j]=(i-1)*m+j;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=4;k++) {
                int x=i+dx[k],y=j+dy[k];
                if(a[x][y]=='#'&&a[i][j]=='#') f[getf((x-1)*m+y)]=getf((i-1)*m+j);
            }
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cnt+=a[i][j]=='#';
    puts(cnt==n+m-1&&getf(1)==getf(n*m)?"Possible":"Impossible");
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
