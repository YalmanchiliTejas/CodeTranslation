#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
long long x,y,z,p=0; cin>>x>>y>>z;
x-=(2*z);
while(x>=y)
{
    p++; x-=(y+z);
}
cout<<p;
return 0;
}