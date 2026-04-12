#include <iostream>
#include <string>
using namespace std;

int main()
{
int r,g,b,z;
cin>>r>>g>>b;
z=r*100+g*10+b;
if(z%4==0)
       cout<<"YES";
else
       cout<<"NO";




    return 0;
}