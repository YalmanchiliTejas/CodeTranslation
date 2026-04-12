#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin>>n;

    int a[n];
    multiset<int>s;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        auto j=s.lower_bound(-a[i]+1);
        if(j==s.end())
        {
            s.insert(-a[i]);
        }
        else
        {
            s.erase(j);
            s.insert(-a[i]);
        }
    }

    cout<<s.size();
}