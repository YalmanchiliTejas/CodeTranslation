#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fi first
#define sec second
#define pr priority_queue
ll mod = 1000000007;
int main(){
  int n;
  cin>>n;
  ll a[n],q=0;
  ll s=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    s=(s+a[i]+mod)%mod;
  }
  for(int i=0;i<n;i++){
    ll d=(s-a[i]+mod)%mod;
    ll k=(a[i]*d)%mod;
    q=(q+k)%mod;
    s=(s-a[i]+mod)%mod;
  }
  cout<<q;
}
