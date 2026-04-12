#include<bits/stdc++.h>
using namespace std;
long long x,y,z;               
int main()
{
    cin>>x>>y>>z;
    x-=z;
    cout<<x/(y+z);
    cout<<"\n";
    return 0;
}