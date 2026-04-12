#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int m1,m2,s1,s2,s3,s4,min1,min2;
    m1=min(x,y);
    s1=m1*(a+b);
    s2=2*m1*c;
    min1=min(s1,s2);
    if(x>y)
        s3=abs(x-y)*a;
    else
        s3=abs(x-y)*b;
        s4=abs(x-y)*2*c;
        min2=min(s3,s4);
        cout<<min1+min2<<endl;
        return 0;
}
