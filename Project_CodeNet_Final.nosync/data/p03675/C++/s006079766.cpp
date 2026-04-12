#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    long long int n,i,j,k;
    vector<long long int>v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);

    }
    if(n%2==0)
    {
        for(i=n-1;i>=0;i-=2)
        {
            cout<<v[i]<<" ";
        }
        for(i=0;i<n;i+=2)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
         for(i=n-1;i>=0;i-=2)
        {
            cout<<v[i]<<" ";
        }
        for(i=1;i<n;i+=2)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


