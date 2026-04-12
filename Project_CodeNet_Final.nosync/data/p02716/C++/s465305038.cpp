#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];

  if(n%2==0) {
    long x=0;
    for(long i=0;i<n;i+=2) {
      x+=a[i];
    }
    ans=x;
    for(long i=n-1;i>0;i-=2) {
      x+=a[i]-a[i-1];
      ans=max(ans,x);
    }
  } else {
    vector<vector<long>> aa(n/2,vector<long>(3));
    aa[n/2-1][2]=a[n-1];
    aa[n/2-1][1]=max(aa[n/2-1][2],a[n-2]);
    aa[n/2-1][0]=max(aa[n/2-1][1],a[n-3]);
    for(long i=n/2-2;i>=0;i--) {
      aa[i][2]=aa[i+1][2]+a[i*2+2];
      aa[i][1]=max(aa[i][2],aa[i+1][1]+a[i*2+1]);
      aa[i][0]=max(aa[i][1],aa[i+1][0]+a[i*2]);
    }
    ans=max(aa[0][0],max(aa[0][1],aa[0][2]));
  }
  cout << ans << endl;
}