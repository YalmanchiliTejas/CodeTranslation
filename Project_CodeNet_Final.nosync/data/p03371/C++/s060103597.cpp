#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    priority_queue<ll> q;
    q.push(-((a*x)+(b*y)));
    ll mul=(x*2)*c;
    if(x<y)
        mul+=(y-x)*b;
    q.push(-mul);
    mul=y*c*2;
    if(y<x)mul+=(x-y)*a;
    q.push(-mul);
    cout<<abs(q.top());
    return 0;
}
