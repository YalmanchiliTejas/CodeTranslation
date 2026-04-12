#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,ans=0,j=0,c=0,k=0,p,x=0;
    cin>>n;
    int a[n+2],b[n+2];
    for(i=0; i<n; i++)
    {
        cin>>a[i];

    }
    j=0;
    if(n%2==0)
    {
        for(i=0; i<n; i++)
        {
            k=i+1;
            if(k%2==0)
            {
                b[j++]=a[i];
            }

        }
        x=j;
        for(p=j-1; p>=0; p--)
            cout<<b[p]<<" ";
        for(i=0; i<n; i++)
        {
            k=i+1;
            if(k%2!=0)
            {
                b[j++]=a[i];
            }

        }
        for(p=x; p<j; p++)
            cout<<b[p]<<" ";
    }
    else
    {
        for(i=n-1; i>=0; i-=2)
        {
            cout<<a[i]<<" ";
        }
        for(i=1; i<n; i+=2)
        {
            cout<<a[i]<<" ";
        }



    }
}
