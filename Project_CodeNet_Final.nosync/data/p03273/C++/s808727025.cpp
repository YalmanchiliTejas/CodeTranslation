#include <iostream>
#include <string>

using namespace std;

int H, W;
string s[100];
bool a[100], b[100];
int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> s[i];
  }
  
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (s[i][j] == '#') {
        a[i] = true;
        b[j] = true;
      }
    }
  }
  
  for (int i = 0; i < H; ++i) {
    if (!a[i]) continue;
    for (int j = 0; j < W; ++j) {
      if (!b[j]) continue;
      cout << s[i][j];
    }
    cout << endl;
  }
}