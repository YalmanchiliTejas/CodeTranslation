#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int>vec(n);
  int ans=1;
  for(int i=0;i<n;i++){
    cin >> vec[i];
  }
  int s=vec[0];
  for(int i=1;i<n;i++){
    s=max(s,vec[i]);
    if(s<=vec[i]){
      ans++;
    }
  }
  cout << ans;
}
