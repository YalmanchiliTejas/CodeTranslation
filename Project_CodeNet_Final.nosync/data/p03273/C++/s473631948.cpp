#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    vector<string> s;
    string tmp;
    bool tate = true;
    bool kai = false;
     
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        cin >> tmp;
        s.push_back(tmp);
    }

    for (int i = 0; i < h; i++) {
        if ((int)s[i].find('#') == -1) {
          for (int j = 0; j < w; j++) {
              s[i][j] = 'A';
          }
        }
    }
    
  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      if (s[i][j] == '#') tate = false;
    }
    if (tate == true) {
      for (int i = 0; i < h; i++) {
        s[i][j] = 'A';
      }
    }
    tate = true;
  }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
      	  if (s[i][j] != 'A') {
              cout << s[i][j];
              kai = true;
          }
      }
      if (kai == true) {
          cout << endl;
      }
      kai = false;
    }
}
