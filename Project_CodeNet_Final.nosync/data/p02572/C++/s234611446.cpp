#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,total,ans;cin >> n;
  vector<long long> a(n),b(n);
  total=0;
  ans=0;
  for (int i=0;i<n;i++) {
    cin >> a[i];
	total+=a[i];
    b[i]=total;
  }
  for (int i=0;i<n-1;i++) {

    ans+=(a[n-1-i]*(b[n-i-2]%1000000007))%1000000007;
  }
  cout << ans%1000000007 << endl;
}