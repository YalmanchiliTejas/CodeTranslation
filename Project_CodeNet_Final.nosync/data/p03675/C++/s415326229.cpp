#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,b,i;
    long long int  v[200000];

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>> v[i];
    }



    if(n%2==0)
    {
        for(i=n-1; i>0; i=i-2)
            cout<<v[i]<<" ";
        for(i=0; i<n; i=i+2)
            cout<<v[i]<<" ";
    }
    else
    {
        for(i=n-1; i>=0; i=i-2)
            cout<<v[i]<<" ";
        for(i=1; i<n; i=i+2)
            cout<<v[i]<<" ";
    }


}
