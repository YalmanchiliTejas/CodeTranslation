#include<bits/stdc++.h>

using namespace std;

int main()
{
  int H, W;
  string S[8];
  cin >> H >> W;

  int ret = 0;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(int j = 0; j < W; j++) {
      ret += S[i][j] == '#';
    }
  }

  if(ret == H + W - 1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }

}