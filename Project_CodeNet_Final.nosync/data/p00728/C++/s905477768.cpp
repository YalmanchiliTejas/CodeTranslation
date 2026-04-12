#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int i,j,n,a[100],ans;
  while(1){
    cin >> n;
    if(n == 0) break;
    for(i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int m = n;
    ans = 0;
    for(i=1;i<n-1;i++){
      ans += a[i];
    }
    ans /= (n - 2);
    cout << ans << endl;

  }
  return 0;
}