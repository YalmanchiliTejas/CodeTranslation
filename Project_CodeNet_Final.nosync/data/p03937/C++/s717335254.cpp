#include <bits/stdc++.h>
using namespace std;
int main () {
  int H, W;
  cin >> H >> W;
  char a;
  int count = 0;
  for(int i = 0; i < H * W; i++){
    cin >> a;
    if(a == '#')count++;
  }
  cout << (count == H + W - 1?"Possible":"Impossible") << endl;
  return 0;
}