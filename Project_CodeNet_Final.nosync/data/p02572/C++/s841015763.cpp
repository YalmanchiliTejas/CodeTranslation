#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = (int)1e9 + 7;

signed main()
{
       int ans = 0;
       int n; cin>>n;
int ar[n];
int sum = 0;
for (int i=0; i<n; ++i)
cin>>ar[i],sum+=ar[i],sum%=mod;

for (int i=0; i<n; ++i)
{
sum-=ar[i];
sum+=mod;
sum%=mod;
ans+=(ar[i]*sum)%mod; 
ans%=mod;
}
cout<< ans <<endl;
}
