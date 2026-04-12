#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef set <int> se;
typedef long long ll;
#define endl "\n"

#define mod 1000000007


int main()
{
 
 ll n;
 cin>>n;
  ll arr[n];
 for(int i  = 0;i<n;i++) {
     cin>>arr[i];
}
    ll sum[n]; 
    sum[n - 1] = arr[n - 1];  //
    for (int i = n - 2; i >= 0; i--)  
        sum[i] = (sum[i + 1] + arr[i])%mod; 
      
    ll res = 0; 
    for (int i = 0; i < n - 1; i++)  
        res = (res%mod+ (sum[i + 1] * arr[i])%mod)%mod; 
 

 
 cout<<res<<endl;

return 0;
   
}