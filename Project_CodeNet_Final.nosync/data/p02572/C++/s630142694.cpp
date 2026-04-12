/*
17/10/2017
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
ll ans=0;
ll sm=0;
for(int i=0;i<n;i++)
{
cin>>a[i];
sm=(sm+a[i])%mod;
}
for(int i=0;i<n;i++)
{
sm=(sm-a[i]+mod)%mod;
ans=(ans+(sm*a[i])%mod)%mod;
}
cout<<ans;
}
