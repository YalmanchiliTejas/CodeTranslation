#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;cin>>n;
  vector<int> H(n);
  for(int i = 0; i < n; i++) cin >> H[i];
  int ans = 1;
  int h = 1;
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(H[i]<H[j]) h = 0;
    }
    if(h) ans++;
    h = 1;
  }
  cout << ans << endl;
}