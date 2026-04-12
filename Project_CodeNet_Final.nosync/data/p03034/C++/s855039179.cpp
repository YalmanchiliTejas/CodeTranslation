#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0,s;
  cin >> n;
  vector<long> aaa(n/2);
  vector<long> bbb(n/2,-1);
  for(long i=0;i<n;i++) {
    cin >> s;
    if(i*2+1!=n) aaa[min(i,n-i-1)]+=s;
  }
  for(long i=1;i<n/2;i++) {
    long x=0;
    for(long j=i;n-j>i;j+=i) {
      if(bbb[min(j,n-j-1)]==i) break;
      if(j*2+1==n) break;
      x+=aaa[min(j,n-j-1)];
      bbb[min(j,n-j-1)]=i;
      ans=max(ans,x);
    }
  }
  cout << ans << endl;
}