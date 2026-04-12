#include<bits/stdc++.h>
using namespace std;
long long int  mod=1000000007;
 
int main()
{
 
 int n;
 cin>>n;
 
 
 long long int a=0;
 long long int s=0;
 long long int answer=0;
 for(int i=0;i<n;i++)
 {
     cin>>a;
     a=a%mod;
     long long b=((s%mod)*(a%mod))%mod;
     answer=(answer+(b))%mod;
     
     s+=a;
 }
 cout<<(answer)<<endl;
return 0;
}