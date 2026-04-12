#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    long long x,y,z;
    cin>>x>>y>>z;
    long long ans;
    ans=(x-z)/(y+z);
    cout<<ans;
    return 0;
}
