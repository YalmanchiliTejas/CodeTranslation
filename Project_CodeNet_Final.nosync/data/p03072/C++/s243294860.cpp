#include<iostream>
using namespace std;
int n,a[150],maxn=0,ans=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=maxn)
        {
            ans++;
            maxn=a[i];
        }
    }
    cout<<ans<<endl;
}
