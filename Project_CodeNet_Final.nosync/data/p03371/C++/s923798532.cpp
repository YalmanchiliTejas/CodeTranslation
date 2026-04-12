#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{   int max(int a,int b);
int max1(int x,int y,int z);
    int a,b,c,n,m;
    int answer,s1,s2,s3;
    while(cin>>a>>b>>c>>n>>m)
    {
        if(n>m)
        {
            s1=(n-(n-m))*2*c+(n-m)*a;
            s2=n*c*2;
        }
        else
        {
         s2=m*c*2;

        s1=(m-(m-n))*2*c+(m-n)*b;
        }
        s3=m*b+n*a;

     answer=max1(s1,s2,s3);
        cout<<answer<<endl;


    }
}
int max(int a,int b)
{
    return a<b?a:b;
}
int max1(int x,int y,int z)
{   int a;
     a=max(x,y);
    return a<z?a:z;
}