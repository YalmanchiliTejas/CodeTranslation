#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>


using namespace std;


int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int s=x*a+y*b;
    int l=0;
    int h=0;
    int g=0;
    int m=min(x,y);
    int n=max(x,y);
    if(x>y)
    {
        l=2*m*c+(x-y)*a;
        h=2*n*c;
        g=min(l,h);
    }
    else
    {
        l=2*m*c+(y-x)*b;
        h=2*n*c;
        g=min(l,h);
    }
    int kqy=min(s,g);
    cout<<kqy;

    return 0;
}