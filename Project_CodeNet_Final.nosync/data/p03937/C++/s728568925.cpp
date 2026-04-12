#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int h, w;
  cin >> h >> w;
  
  char c;
  int count = 0;
  for(int i = 0; i < h * w; i++){
    cin >> c;
    if(c == '#') count++;
  }
  
  if(count == h + w - 1) cout << "Possible\n";
  else cout << "Impossible\n";
}