#include <iostream>
#include <iomanip>

#define debug(x) cout << #x << "==" << x << endl;

const int INF = 1e+9 + 7;

using namespace std;

//入力
// #define MAX_N
char c;

int main() {
  ios::sync_with_stdio(false);

  cin >> c;

  if( c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }



  return 0;
}
