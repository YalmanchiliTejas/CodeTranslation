#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
int n,x,ans; 
cin>>n;
x=n/15;
ans=floor(x) ;
cout<<(n*800)-(ans*200);
return 0;
}