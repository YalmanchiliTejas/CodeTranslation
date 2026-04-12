#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin>>a>>b>>c>>x>>y;

    int res=INT_MAX;
    for(int i=0; i<=x; ++i) res=min(res, a*i+c*2*(x-i)+b*max(0, y-(x-i)));
    for(int i=0; i<=y; ++i) res=min(res, b*i+c*2*(y-i)+a*max(0, x-(y-i)));
    cout<<res<<endl;
}
