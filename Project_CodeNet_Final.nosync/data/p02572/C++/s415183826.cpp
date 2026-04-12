#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
int main(){
	int n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++){
     cin>>ar[i];
    }
   vector<ll>suffix(n);
   suffix[n-1]=ar[n-1]%mod;
  for(int j=n-2;j>=0;j--){
     suffix[j]=(suffix[j+1]%mod+ar[j]%mod)%mod;
   }
  ll sum=0;
    for(int i=1;i<n;i++){
      ll k=(ar[i-1]%mod)*(suffix[i]%mod);
       sum=sum+(k)%mod;
  }
 cout<<sum%mod<<endl;
	return 0;
}