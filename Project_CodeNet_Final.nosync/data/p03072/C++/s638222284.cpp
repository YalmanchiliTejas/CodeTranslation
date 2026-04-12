#include <bits/stdc++.h>
using namespace std;


int main() {
  int n; cin >> n;
  int H[n];
  for(int i = 0; i < n; i++) cin >> H[i];
  int cnt = 1;
  int h = H[0];
  for(int i = 1; i < n; i++){
    if(H[i]>=h) cnt++;
    if(h<H[i]) h = H[i];
  }
  cout << cnt << endl;
}