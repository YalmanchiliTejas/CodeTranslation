#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  string s;
  cin >> s;
  char prev_ch = s[0];
  bool result = false;
  for (int i = 0; i < s.size(); i++) {
    if (prev_ch != s[i]) {
      result = true;
      break;
    }
  }

  cout << (result ? "Yes\n" : "No\n");
  return 0;
}