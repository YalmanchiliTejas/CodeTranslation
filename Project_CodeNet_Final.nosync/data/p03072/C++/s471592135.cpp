#include <bits/stdc++.h>
using namespace std;
long long n;
void solve()
{
    long long ans=0,tmp=0;
    while(n--)
    {
        long long x;
        cin>>x;
        if (!tmp) {tmp=x;ans++;}
        else if (x>=tmp) {tmp=x;ans++;}
    }
    cout<<ans<<endl;
}
int main()
{
    while(cin>>n)
        solve();
    return 0;
}