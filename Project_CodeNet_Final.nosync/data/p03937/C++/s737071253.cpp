#include <bits/stdc++.h>
using namespace std;

int h, w;
string a[8];
bool ok = false;
int num_sharp = 0;

void dfs(int i, int j, int cnt) {
  if (i == h - 1 && j == w - 1 && num_sharp == cnt) {
    ok = true;
    return;
  }
  if (i < h - 1 && a[i+1][j] == '#') {
    dfs(i+1, j, cnt+1);
  }
  if (j < w - 1 && a[i][j+1] == '#') {
    dfs(i, j+1, cnt+1);
  }
}
int main() {
  cin>>h>>w;
  for (int i=0; i<h; i++) cin>>a[i];
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (a[i][j] == '#') {
        ++num_sharp;
      }
    }
  }
  dfs(0, 0, 1);
  if (ok) {
    cout<<"Possible"<<endl;
  } else {
    cout<<"Impossible"<<endl;
  }
}