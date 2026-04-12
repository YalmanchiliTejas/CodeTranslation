#include <bits/stdc++.h>
using namespace std;
long long n;
void solve()
{
    string a;
    cin>>a;
    long long i,k;
    cin>>k;
    for (i=0;i<a.length();i++)
        if (a[i]==a[k-1]) cout<<a[i];
        else cout<<"*";
    cout<<endl;
}
int main()
{
    while(cin>>n)
        solve();
    return 0;
}