#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    long long n;
    cin>>n;
    long long *arr=new long long[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long *pre=new long long[n];
    pre[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=(arr[i]+pre[i-1])%mod;
    }
    long long sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum=(sum+(arr[i]*(pre[n-1]-pre[i])))%mod;
    }
    cout<<(sum+mod)%mod<<endl;
}