#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],ans=1,m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    m=a[0];
    for(int i=1;i<n;i++)
    {
        if(m<=a[i])
        {
            ans++;
            m=a[i];
        }
    }
    cout<<ans<<endl;
}
