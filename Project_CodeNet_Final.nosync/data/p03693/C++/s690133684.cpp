#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int d;
        d=a*100+b*10+c;
        int flag=0;
        if(d%4!=0)
            flag=1;
        if(!flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
