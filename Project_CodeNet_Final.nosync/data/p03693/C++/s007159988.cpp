#include <bits/stdc++.h>
using namespace std;
int r,g,b;
void solve()
{
    if ((100*r+10*g+b)%4==0) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
int main()
{
    while(cin>>r>>g>>b)
        solve();
}