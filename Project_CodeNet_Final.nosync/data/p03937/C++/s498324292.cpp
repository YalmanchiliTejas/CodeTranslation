#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  int sum = 0;
  char a;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a;
      sum += a == '#' ? 1 : 0;
    }
  }
  cout << (sum == h + w - 1 ? "Possible" : "Impossible") << endl;
  return 0;
}