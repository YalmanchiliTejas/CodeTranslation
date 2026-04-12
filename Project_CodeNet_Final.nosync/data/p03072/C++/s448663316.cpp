#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  int ans = 1;
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  for(int i = 1; i < n; i++){
    bool flag = true;
    for(int j = 0; j < i; j++){
      if(h[i] < h[j]){
        flag = false;
      }
    }
    if(flag){
      ans++;
    }
  }
  cout << ans << endl;
}