#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int h[1000];
  for(int i=0;i<n;i++){
    cin >> h[i];
  }
  int maxs = 0;
  int ans = 0;
  for(int i=0;i<n;i++){
    if(maxs<=h[i]){
      ans++;
      maxs = h[i];
    }
  }
  cout << ans << endl;
}
