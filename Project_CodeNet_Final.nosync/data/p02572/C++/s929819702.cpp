#include<bits/stdc++.h>
using namespace std;

#define MODULUS 1000000007

int main()
{

    int n;
    cin>>n;

    long long int a[n];
    long long int sum[n],ans[n],totalsum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        totalsum = (totalsum + a[i])%MODULUS;
        sum[i] = totalsum;
    }

    for(int j=0;j<n;j++)
    {
        ans[j] = ((totalsum - sum[j])%MODULUS + MODULUS)%MODULUS;
    }

    long long int finalans = 0;
    for(int k=0 ;k<n-1;k++)
    {
        finalans = (finalans+ ((a[k])%MODULUS*(ans[k]%MODULUS)))%MODULUS;
    }
    cout<<finalans<<endl;
    return 0;
}