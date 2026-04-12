#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0); cin.tie(NULL);
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main(){
    fastIO
    
    int n; cin>>n;
    
    int a[n];
    
    ll sum = 0;
    
    for(int i=0; i<n; i++){
      
      cin>>a[i];
      
      sum+=a[i];
      
      sum%=mod;
    }
    
    ll ans=0;
    for(int i=0; i<n; i++){
      
      sum-=a[i];
      
      if(sum<0) sum+=mod;
      
      ans+=(a[i]*sum);
      
      ans%=mod;
      
    }
    cout<<ans;
    return 0;
}