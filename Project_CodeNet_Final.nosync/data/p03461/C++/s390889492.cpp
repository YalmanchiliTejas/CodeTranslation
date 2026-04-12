#include<iostream>
#include<cstdio>
#define MN 200
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int A,B,d[35][35],b[35][35],m;
struct edge{int x,y,w;}e[MN*MN+5];
int main()
{
    A=read();B=read();
    for(int i=1;i<=A;++i) for(int j=1;j<=B;++j) d[i][j]=read();
    for(int i=0;i<=100;++i) for(int j=0;j<=100;++j)
    {
        int mn=0;
        for(int k=1;k<=A;++k) for(int l=1;l<=B;++l) mn=max(mn,d[k][l]-k*i-l*j);
        e[++m]=(edge){i+1,202-j,mn};
        for(int k=1;k<=A;++k) for(int l=1;l<=B;++l) if(k*i+j*l+mn==d[k][l]) b[k][l]=1;
    }
    for(int i=1;i<=A;++i) for(int j=1;j<=B;++j) if(!b[i][j]) return 0*puts("Impossible");
    printf("Possible\n%d %d\n",202,m+200);
    for(int i=1;i<=100;++i) printf("%d %d X\n",i,i+1),printf("%d %d Y\n",i+101,i+102);
    for(int i=1;i<=m;++i) printf("%d %d %d\n",e[i].x,e[i].y,e[i].w);
    puts("1 202");
    return 0;
}
