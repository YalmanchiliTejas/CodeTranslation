#include<bits/stdc++.h>
#define ll long long 
using namespace std;
signed main(){
  ll n,a[100000],cun=0;
  cin>>n;
  for(ll i=0;i<n;i++){
	cin>>a[i];
  }
  ll ma = a[0];
  for(ll i=0;i<n;i++){
	if(ma<=a[i]){
      cun++;
      ma = a[i];
    }
  }
  cout<<cun<<"\n";
}