// tenka12019_b

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
  int n, k;
  string s;
  char c;
  cin >> n >> s >> k;

  c = s[k-1];
  for (int i=0; i < n; i++) {
    if (s[i]!=c) {
      s[i]='*';
    }
  }
  cout << s << endl;
  return 0;
}
