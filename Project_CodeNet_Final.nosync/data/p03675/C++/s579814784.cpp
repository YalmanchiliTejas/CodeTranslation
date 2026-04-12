#include<iostream>
using namespace std;

int main()
{
    long long n,i,j;
    cin>>n;
    long long a[n+2];
    if((n%2)==1)
    {
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(i=n-1; i>=0; i-=2)
        {
            cout<<a[i]<<" ";
        }

        i+=2;
        for(j=i+1; j<n; j+=2)
        {
            cout<<a[j]<<" ";
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(i=n-1; i>=0; i-=2)
        {
            cout<<a[i]<<" ";
        }
        for(j=i+1; j<n; j+=2)
        {
            cout<<a[j]<<" ";
        }
    }
    return 0;
}
