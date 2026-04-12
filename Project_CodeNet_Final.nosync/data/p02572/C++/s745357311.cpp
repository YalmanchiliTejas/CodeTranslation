#include <bits/stdc++.h>
using namespace std;

int mod=1000000007;

long long arr[200004];
int rarr[200004];
int main()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        rarr[i]=x;
        arr[i]+=(arr[i-1]+x);
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        long long temp=(((arr[n]-arr[i])%mod)*rarr[i])%mod;
        sum=(sum+temp)%mod;
    }
    cout<<sum<<endl;
}

