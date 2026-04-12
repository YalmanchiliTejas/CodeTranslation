#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0,m=0,b;
  for(int i=0;i<n;i++){
    cin >> b;
    if(b>=m)
      ans++;
    m=max(m,b);
  }
  cout << ans << endl;
  return 0;
}