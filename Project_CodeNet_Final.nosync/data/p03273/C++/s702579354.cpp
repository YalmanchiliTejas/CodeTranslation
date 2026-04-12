#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  char a[100][100];

  vector<int> remI, remJ;
  for (int i = 0; i < H; i++) {
    bool flag = false;
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#')
        flag = true;
    }
    if (!flag) {
      remI.push_back(i);
    }
  }

  for (int j = 0; j < W; j++) {
    bool flag = false;
    for (int i = 0; i < H; i++) {
      if (a[i][j] == '#')
        flag = true;
    }
    if (!flag) {
      remJ.push_back(j);
    }
  }

  // output
  for (int i = 0; i < H; i++) {
    if (std::find(remI.begin(), remI.end(), i) != remI.end())
      continue;
    for (int j = 0; j < W; j++) {
     if (std::find(remJ.begin(), remJ.end(), j) != remJ.end())
       continue;
     cout << a[i][j];
    }
    cout << endl;
  }
}
