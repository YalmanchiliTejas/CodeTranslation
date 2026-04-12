#include<bits/stdc++.h>

using namespace std;

int a,b,c,y,x,kq;

void    init()
{
    freopen("c.inp","r",stdin);
    freopen("c.out","w",stdout);
}

void    nhap()
{
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
}

void    xuly()
{
    int kq1=a*x+b*y;
    int kq2=0;
    if (x<y)
        kq2=c*x*2+b*(y-x);
    else
        kq2=c*y*2+a*(x-y);
    int kq3=0;
    if (x<y)
        kq3=c*y*2;
    else
        kq3=c*x*2;
    kq=min(kq1,min(kq2,kq3));
}

void    xuat()
{
    printf("%d",kq);
}

int     main()
{
    //init();
    nhap();
    xuly();
    xuat();
}

