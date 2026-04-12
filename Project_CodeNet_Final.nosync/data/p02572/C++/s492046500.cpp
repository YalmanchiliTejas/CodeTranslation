#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  rep(i,n) cin >> a.at(i);
  long long sum=0;
  rep(i,n){
    sum+=a.at(i);
    sum%=(1000000007*2);
  }
  long long sum_sq=0;
  rep(i,n){
    long long t;
    t=(a.at(i)*a.at(i))%(1000000007*2);
    sum_sq+=t;
    sum_sq%=(1000000007*2);
  }
  long long ans;
  ans = (sum*sum-sum_sq)/2;
  if(ans<0) ans+=1000000007;
  ans%=1000000007;
  cout << ans << endl;
  return 0;
}