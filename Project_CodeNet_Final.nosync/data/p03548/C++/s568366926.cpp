#include <bits/stdc++.h>
#define INT long long
#define oo (int)(1e9)+1
using namespace std;

int x, y, z;

int main()
{
    ios::sync_with_stdio(false);
    cin>>x>>y>>z;
    x-=z;
    cout<<max(0, x/(y+z))<<endl;
}
