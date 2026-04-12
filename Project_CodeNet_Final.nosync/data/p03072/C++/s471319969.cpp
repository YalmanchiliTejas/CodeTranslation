#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int h[n];
  for(int i=0;i<n;i++)cin>>h[i];
  int ans=0,max=1;
  for(int i=0;i<n;i++){
    if(h[i]>=max){
      max=h[i];
      ans++;
    }
  }
  cout << ans;
  return 0;
}
