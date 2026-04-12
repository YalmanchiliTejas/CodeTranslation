#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
     int a,b,c;
     while(scanf("%d%d%d",&a,&b,&c)==3)
     {
        int sum=a*100+b*10+c,flag;
     if(sum%4==0)
        flag=1;
     else
        flag=0;
     printf("%s\n",flag==1?"YES":"NO");

     }
     return 0;

}
