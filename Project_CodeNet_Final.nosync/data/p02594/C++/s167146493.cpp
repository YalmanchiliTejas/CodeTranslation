#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
    if(x>=30)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    }
    return 0;
}
