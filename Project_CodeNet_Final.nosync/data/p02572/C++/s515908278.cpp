  #include <unordered_map>
  #include <functional>
  #include <algorithm>
  #include <iostream>
  #include <climits>
  #include <vector>
  #include <stack>
  #include <queue>
  #include <map>
  #include <set>
  #define mod 1000000007
  using namespace std;
  #define ll long long int
    
  
  int main()
  {
  ll n;
  cin>>n;
  ll a[n];
  for(int i=0;i<n;i++) 
    {
      cin>>a[i];
    }
  ll suffix[n];
  suffix[n-1]=a[n-1];
   for(int i=n-2;i>=0;i--)
   {
    suffix[i]=(suffix[i+1]+a[i])%mod;
   }
   ll ans=0;
   for(int i=0;i<n-1;i++)
   {
    ans=(ans+(a[i]*suffix[i+1])%mod)%mod;
   }
   cout<<ans;
 }
