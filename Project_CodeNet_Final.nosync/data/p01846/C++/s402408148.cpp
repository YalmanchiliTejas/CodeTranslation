#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  int A, B, C, D;
  bool mas[9][9];

  while(cin >> S, S != "#") {
    cin >> A >> B >> C >> D;

    memset(mas, false, sizeof(mas));
    int y = 0, x = 0;
    for(char &c : S) {
      if(c == '/') y++, x = 0;
      else if(isdigit(c)) x += c - '0';
      else mas[y][x++] = true;
    }
    swap(mas[--A][--B], mas[--C][--D]);
    for(int i = 0; i <= y; i++) {
      if(i > 0) cout << "/";
      int ret = 0;
      for(int j = 0; j < x; j++) {
        if(mas[i][j]) {
          if(ret > 0) cout << ret;
          cout << "b";
          ret = 0;
        } else {
          ++ret;
        }
      }
      if(ret > 0) cout << ret;
    }
    cout << endl;
  }
}