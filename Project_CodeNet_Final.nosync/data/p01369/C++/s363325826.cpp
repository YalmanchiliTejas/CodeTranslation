#include <iostream>
#define REP(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;

string S;
int hand[26] = {
  0, 0, 0, 0, 0,
  0, 0, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 0, 0, 0, 0,
  1, 0, 0, 0, 1,
  0
};

int main(void) {
  while(cin >> S, S != "#") {
    int ans = 0;
    REP(i, 0, S.length() - 1) if(hand[S[i] - 'a'] != hand[S[i + 1] - 'a']) ans++;
    cout << ans << endl;
  }

  return 0;
}