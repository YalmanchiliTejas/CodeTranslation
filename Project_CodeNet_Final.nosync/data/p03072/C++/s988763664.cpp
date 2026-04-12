#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans=0;
  cin >> n;
  long long h[n],highest=0;
  for(int i=0;i<n;i++){
    cin >> h[i];
    if(highest<=h[i]){
      highest=h[i];
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
