#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
  int n;
  cin >> n;
  long* a = new long[100000];
  long ans = 0;
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  if(n%2==0){
    for(int i=0;i<n;i++){
      if(i<n/2-1){
        ans -= a[i] * 2;
      } else if (i == n/2 -1){
        ans -= a[i];
      } else if (i == n/2){
        ans += a[i];
      } else {
        ans += a[i] * 2;
      }
    }
  } else {
    long cand = 0;
    for(int i=0;i<n;i++){
      if(i < n/2 - 1){
        ans -= a[i] * 2;
      } else if (i == n/2 || i == n/2 - 1){
        ans -= a[i];
      } else {
        ans += a[i] * 2;
      }
    }
    for(int i=0;i<n;i++){
      if(i > n/2 + 1){
        cand += a[i] * 2;
      } else if (i == n/2 || i == n/2 + 1){
        cand += a[i];
      } else {
        cand -= a[i] * 2;
      }
    }
    ans = max(ans,cand);
  }

  cout << ans << endl;
  return 0;
}
