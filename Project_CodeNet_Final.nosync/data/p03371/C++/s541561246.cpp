#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double calc(double a,double b,double c,double x,double y)
{
    double cost1=0,cost2=0;
    double tx,ty;
    tx=x,ty=y;
    if(a>=2*c)
    {
        cost1=(x*c*2);
        y-=x/2;
        x=0;
        if(y>0)
            cost1+=min(ceil(y)*b,y*c*2);
    }
    else
    {
        if(b>=2*c)
        {
            cost1=(y*c*2);
            x-=y/2;
            y=0;
            if(x>0)
                cost1+=min(ceil(x)*a,x*c*2);
        }
        else
        {
            cost1=x*a;
            cost1+=y*b;
        }
    }
    x=tx;
    y=ty;
    if(b>=2*c)
    {
        cost2=(y*2*c);
        x-=y/2;
        y=0;
        if(x>0)
            cost2+=min(ceil(x)*a,x*c*2);
    }
    else
    {
        if(a>=2*c)
        {
            cost2=(x*2*c);
            y-=x/2;
            x=0;
            if(y>0)
                cost2+=min(ceil(y)*b,y*c*2);
        }
        else
        {
            cost2=x*a;
            cost2+=y*b;
        }
    }
    return min(cost1,cost2);
}
int main()
{
    double a,b,c,x,y;
    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&x,&y);
    double tx,ty,xx,yy,cost=-1,costf;
    tx=min(x,y);
    xx=x,yy=y;
    if(tx*a+tx*b>=2*tx*c)
    {
        cost=2*tx*c;
        xx-=tx;
        yy-=tx;
        if(xx>0)
        {
            if(a*xx>=c*xx*2)
                cost+=c*xx*2;
            else
                cost+=a*xx;
        }
        else
        {
            if(b*yy>=c*yy*2)
                cost+=c*yy*2;
            else
                cost+=b*yy;
        }
    }
    double cost1=calc(a,b,c,x,y);
    if(cost!=-1)
    {
        costf=min(cost1,cost);
    }
    else
        costf=cost1;
    printf("%0.0f\n",costf);
}
