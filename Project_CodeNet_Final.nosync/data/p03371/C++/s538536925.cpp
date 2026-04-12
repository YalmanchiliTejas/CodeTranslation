#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b,c,x,y,i,j,k,l,s1,s2,s3;
    cin>>a>>b>>c>>x>>y;
    s1=0;
    s2=0;
    s3=0;
    s1+=a*x+b*y;
    if(x<=y)
    {
        k=x;
        l=y;
        s2+=k*2*c;
        l-=k;
        s2+=l*b;
        s3+=y*c*2;
        if(s3<=s2)
        {
            s2=s3;
        }


    }
    else if(y<x)
    {
        k=x;
        l=y;
        s2+=l*2*c;
        k-=l;
        s2+=k*a;
        s3+=x*c*2;
        if(s3<=s2)
        {
            s2=s3;
        }
    }
    if(s1<=s2)
    {
        cout<<s1<<endl;
    }
    else if(s2<s1)
    {
        cout<<s2<<endl;
    }
return 0;
}
