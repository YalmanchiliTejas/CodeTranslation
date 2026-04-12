#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int x,y,z;
    cin>>x>>y>>z;
    x-=z;
    cout<<x/(y+z);
    return 0;
}
