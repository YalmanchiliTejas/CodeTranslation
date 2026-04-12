#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n,n)
    {
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        int sum=0;
        for(int i=1;i<=n-2;i++)sum+=a[i];
        cout<<sum/(n-2)<<endl;
    }
}
