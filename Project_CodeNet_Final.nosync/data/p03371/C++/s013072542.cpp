#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
long long int a,b,c,x,y;
cin>>a;
cin>>b;
cin>>c;
cin>>x;
cin>>y; 
long long int sum1,sum2,sum3;
if(x>y)
sum1=min(x,y)*c*2+abs(x-y)*a;
else
sum1=min(x,y)*c*2+abs(x-y)*b;
sum2=max(x,y)*c*2;
sum3=a*x+b*y;
cout<<min(min(sum1,sum2),sum3)<<endl;
}