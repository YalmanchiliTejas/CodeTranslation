#include <iostream>

using namespace std;

int main()
{
int a,b;
cin>>a;
cin>>b;

if(1<=a&&a<=100&&0<=b&&b<=a)
{
if(a==b)
    cout<<"Yes";
else
   cout<<"No";
}

else
{
    cout<<"error";
}
    return 0;
}