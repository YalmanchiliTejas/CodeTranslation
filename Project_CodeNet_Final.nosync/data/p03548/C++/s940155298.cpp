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
long long x,y,z,p=0,l; cin>>x>>y>>z;
l=z;
while(l+y+z<=x)
{
    p++; l+=y+z;
}
cout<<p;
return 0;
}
