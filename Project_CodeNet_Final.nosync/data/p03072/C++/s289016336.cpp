#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,h,hmax,i,ans=1;
  cin >> n >> hmax;
  for (i=1;i<n;i++){
    cin >> h;
    if (h>=hmax){
      ans++;
      hmax=h;
    }
  }
  cout << ans << endl;
  return 0;
}