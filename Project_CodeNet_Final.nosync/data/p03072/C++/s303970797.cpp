#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],i,c=0,ans=1,j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=n-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[i]<a[j])
            {
                ans=0;
                break;
            }
        }
        if(ans)
            c++;
        ans=1;
    }
    cout<<c<<endl;
}
