#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define w(t) ll t;cin>>t; while(t--)
ll mod=1000000007;
int main()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
//w(t){
ll i,n,s=0;cin>>n;
   ll a[n],suffix[n+1]={0};
   for(i=0;i<n;i++)
  {
  cin>>a[i];
  }
  for(i=n-1;i>=0;i--)
  suffix[i]=suffix[i+1]+a[i];//cout<<suffix[i];
    for(i=0;i<n;i++)
{//s+=a[i]*suffix[i+1];
    
        s+=((a[i]%mod)*(suffix[i+1]%mod))%mod;
       /// s+=s;
    }
 
cout<<s%mod<<endl;
}