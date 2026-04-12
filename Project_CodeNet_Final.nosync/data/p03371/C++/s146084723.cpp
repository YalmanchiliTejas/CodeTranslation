#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main()
{
    long long int a,b,c,x,y,maxi,mini,p1,p2,p3,m,r;
    cin>>a>>b>>c>>x>>y;
    p1=(a*x+b*y);
    if(x>y){
        m=y;
        r=x-m;
        p2=(m*2*c)+(r*a);
        //cout<<p2<<endl;
    }
    else{
        m=x;
        r=y-m;
        p2=(m*2*c)+(r*b);
        //cout<<p2<<endl;
    }
    if(x>y){
        m=x;
        r=abs(y-m);
        p3=(m*2*c);
    }
    else{
        m=y;
        r=abs(x-m);
        p3=(m*2*c);
    }
//    cout<<p1<<endl;
//    cout<<p2<<endl;
//    cout<<p3<<endl;
    cout<<min(p1,min(p2,p3))<<endl;
}
