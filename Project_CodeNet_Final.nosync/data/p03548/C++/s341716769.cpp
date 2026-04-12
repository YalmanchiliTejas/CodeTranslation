#include <bits/stdc++.h>
#define fast_read ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int main()
{
    fast_read
    int x,y,z;
    cin>>x>>y>>z;
    int e = x / (y + z);
    if (x - e * (y + z) >= z)cout<<e<<endl;
    else cout<<e-1<<endl;
    return 0;
}
