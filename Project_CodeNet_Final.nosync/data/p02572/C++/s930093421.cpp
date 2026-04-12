//Code Author: S.M. Istiak Ahmed
#include<bits/stdc++.h>
#define ll long long
#define INF 100000000000000
#define MOD 1000000007
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  ll arr[n],csum[n];
  for(int i=0; i<n; i++) cin>>arr[i];
  csum[n-2]=arr[n-1];
  for(int i=n-3; i>=0; i--) csum[i]=(csum[i+1]+arr[i+1])%MOD;
  ll ans=0;
  for(int i=0; i<n-1; i++) ans+=((arr[i]%MOD)*(csum[i]%MOD))%MOD;
  cout<<ans%MOD;
  return 0;
}
