#include <iostream>
#include <string>

using namespace std;

enum {
      LEFT,
      RIGHT,
};

int main()
{
  char key_right[] = { 'y', 'u', 'i', 'o', 'p',
                     'h', 'j', 'k', 'l', 'n', 'm' };

  while (1) {
    int last_status = -1;
    int count = 0;
    string str;
    cin >> str;
    cin.ignore();
    if (str == "#") break;
    for (auto s : str) {
      int status = LEFT;
      for (auto key : key_right) {
        if (s == key) {
          status = RIGHT;
          break;
        }
      }
      if (last_status != -1 && last_status != status) {
        count++;
      }
      last_status = status;
    }
    cout << count << endl;
  }
}

