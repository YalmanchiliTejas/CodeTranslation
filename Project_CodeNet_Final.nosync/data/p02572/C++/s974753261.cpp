#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp = boost::multiprecision;
// int64_tは9*10^18まで、intは2*10^9まで

int main() {
  int n;
  cin >> n;
  mp::cpp_int a, ans=0, asum=0, a2sum=0;
  for(int i=0; i<n; i++){
    cin >> a;
    asum+=a;
    a2sum+=a*a;
  }
  ans=(asum*asum)-a2sum;
  ans/=2;
  ans%=1000000007;
  cout << ans;
  return 0;
}