#include <iomanip>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  bool stA = false;
  bool stB = false;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'A') stA = true;
    if (S[i] == 'B') stB = true;
  }
  if (stA && stB)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
