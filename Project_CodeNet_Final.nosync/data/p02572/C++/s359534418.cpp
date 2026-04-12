#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define all(x) x.begin(),x.end()
#define mod 1000000007

ll sum(vector<ll> &a, int n) {
    ll ans = 0, pre_sum = 0; 
    vector<ll> sum(n+1, 0);
    for (int i=n-1; i>=0; i--){
      sum[i] = sum[i+1]+a[i];
      sum[i]%=mod;
    }

    for(int i=0;i<n; i++){
      ans += ((a[i]%mod)*(sum[i+1]%mod))%mod;
      ans%=mod;
    }
    return ans; 
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n);
  for(int i=0; i<n; i++)
    cin>>a[i];
  ll ans = sum(a, n);
  cout<<(ans%mod)<<"\n";
  return 0;
}