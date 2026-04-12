#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H,W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }
  vector<bool> thrH(H);
  vector<bool> thrW(W);
  for (int i = 0; i < H; i++) {
    thrH.at(i) = true;
    for (int j = 0; j < W; j++) {
      if (a.at(i)[j] == '#') {
        thrH.at(i) = false;
        break;
      }
    }
  } 
  for (int j = 0; j < W; j++) {
    thrW.at(j) = true;
    for (int i = 0; i < H; i++) {
      if (a.at(i)[j] == '#') {
        thrW.at(j) = false;
        break;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (thrH.at(i))
      continue;
    for (int j = 0; j < W; j++) {
       if(thrW.at(j) ) 
         continue;
       cout << a.at(i)[j];
     }
     cout << endl;
   } 
}