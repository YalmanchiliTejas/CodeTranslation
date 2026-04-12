#include <iostream>
using namespace std;

bool is_right(char ch)
{
  static const char right[11] = { 'y', 'u', 'i', 'o', 'p',
                            'h', 'j', 'k', 'l',
                             'n', 'm', };
  for (int i = 0; i < 11; ++i)
  {
    if (right[i] == ch) return true;
  }
  return false;
}

int main(void)
{
  cin >> noskipws;
  char buf_ch;
  int sum = 0;
  bool now_right;
  while (true)
  {
    cin >> buf_ch;
    if (buf_ch == '#') break;

    sum = 0;
    now_right = is_right(buf_ch);
    while (true)
    {
      cin >> buf_ch;
      if (buf_ch == '\n') break;

      if (now_right xor is_right(buf_ch) )
      {
        ++sum;
        now_right = is_right(buf_ch);
      }
    }
    cout << sum << endl;
  }
  return 0;
}