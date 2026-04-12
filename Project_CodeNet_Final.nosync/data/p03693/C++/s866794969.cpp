#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
int x,y,z;
cin>>x>>y>>z;
if((x*100+y*10+z)%4==0)
    cout<<"YES"<<endl;
else cout<<"NO"<<endl;

 return 0;
}
