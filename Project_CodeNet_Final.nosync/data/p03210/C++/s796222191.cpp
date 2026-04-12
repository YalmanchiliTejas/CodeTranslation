#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    if (n==3||n==5||n==7) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
int main()
{
    while(cin>>n)
        solve();
}