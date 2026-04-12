#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> r(n+1,0); //累積和
  int mod=1000000007;
  for(int i=0;i<n;i++){
    cin >> a[i];
    r.at(i+1)=r[i]+a[i];
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    long long sum=(r[n]-r[i+1]) % mod;
    ans+=sum*a[i];
    ans%=mod;
  }
  cout << ans << endl;
}