#include <bits/stdc++.h>

using namespace std;

int main()
{
  int H, W;
  string S[8];

  cin >> H >> W;
  for(int i = 0; i < H; i++) cin >> S[i];

  int beet = 0;
  for(int i = 0; i < H; i++) {
    for(auto &c : S[i]) beet += c == '#';
  }
  if(beet == H + W - 1) puts("Possible");
  else puts("Impossible");
}