#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int H,W;
  cin >> H >> W;

  int b = 0;
  for(int i = 0;i < H;i++) {
    for(int j = 0;j < W;j++) {
      char A;
      cin >> A;
      if(A == '#') b++;
    }
  }

  if(b == H+W-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}