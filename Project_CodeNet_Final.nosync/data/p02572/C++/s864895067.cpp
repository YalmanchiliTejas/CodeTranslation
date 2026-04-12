 #include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
#define m 1000000007  


  
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
   ll n;cin>>n;ll a[n]{};ll v[n]{};
   
   for(ll i=0;i<n;i++)cin>>a[i];
   
    for(ll i=n-2;i>=0;i--)
    {
        v[i]=(v[i+1]+a[i+1])%m;
    }
    ll sum=0;
   for(ll i=0;i<n;i++)
   {
       ll k1=((a[i]*v[i])%m);
       sum+=k1;
       sum=(sum%m);
   }
   cout<<(sum%m)<<endl;
     
   
   
    return 0; 
} 