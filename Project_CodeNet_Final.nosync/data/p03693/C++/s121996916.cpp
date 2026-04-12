#include <iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
     int a,b,c;
     scanf("%d%d%d",&a,&b,&c);
     int sum=a*100+b*10+c;
     if(sum%4==0)
        cout<<"YES"<<endl;
     else
        cout<<"NO"<<endl;
     return 0;


}
