#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int n,i,h[25],hmax,ans=1;
  cin >> n;
  for (i=0;i<n;i++) cin >> h[i];
  hmax=h[0];
  for (i=1;i<n;i++){
    if (h[i]>=hmax) ans++;
    if (hmax<h[i]) hmax=h[i];
  }
  cout << ans << endl;
  return 0;
}