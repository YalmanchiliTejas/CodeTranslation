#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  cin >> h >> w;
  bool bw[w]={0};
  bool bh[h]={0};
  vector<vector<char>> data(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    int cnt_w=0;
    for (int j = 0; j < w; j++) {
      cin >> data.at(i).at(j);
      if (data.at(i).at(j)=='#') {
        bw[j] = 1;
        ++cnt_w;
      }
    }
    if (cnt_w !=0) bh[i] = 1;
  }
  for (int i = 0; i < h; i++) {
    if (!bh[i]) continue;
    else {
    for (int j = 0; j < w; j++) {
      if (!bw[j]) continue;
      else {
        cout << data.at(i).at(j);
      }
    }
    cout << endl;
  }
}
}