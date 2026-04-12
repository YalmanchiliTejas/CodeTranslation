#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0;i < n;i++){
    cin >> h.at(i);
  }
  int ans = 1;
  int mxH = h.at(0);
  for(int i = 1;i < n;i++){
    if(h.at(i) >= mxH){
      ans++;
      mxH = h.at(i);
    }
  }

  cout << ans << endl;

  return 0;
}
