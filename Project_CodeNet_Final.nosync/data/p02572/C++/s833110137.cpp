#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int p=1000000007;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll sum=0;
  rep(i,n) sum+=a[i];
  sum%=p;
  ll ans=0;
  rep(i,n){ans+=(sum-a[i]+p)*a[i]%p;ans%=p;}
  ans*=500000004;
  ans%=p;
  cout << ans;
  
  return 0;
}