#include<bits/stdc++.h>
using namespace std;
long long int  mod=1000000007;

int main()
{

 int n;
 cin>>n;


 long long int a=0;
 long long int sum=0;
 long long int ans=0;
 for(int i=0;i<n;i++)
 {
     cin>>a;
     a=a%mod;
     long long b=((sum%mod)*(a%mod))%mod;
     ans=(ans+(b))%mod;
     //ans=ans%mod;
     sum+=a;
 }
 cout<<(ans)<<endl;
return 0;
}
