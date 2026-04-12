#include <iostream>
using namespace std;

int main()
{
  char c; cin >> c;
  char arr[] = {'a', 'e', 'i', 'o', 'u'};
  for(int i = 0; i < 5; ++i) {
    if(c == arr[i]) {
      cout << "vowel";
      return 0;
    }
  }
    cout << "consonant";
    return 0;
}