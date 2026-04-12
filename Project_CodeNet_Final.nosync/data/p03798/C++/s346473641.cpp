#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

bool getAnswer(const string& S, string& T) {
  int N = S.size();
  for (int i = 1; i < N; ++i) {
    if ((S[i] == 'o' && T[i] == 'S') || (S[i] == 'x' && T[i] == 'W')) {
      T += T[i - 1];
    } else {
      T += (T[i - 1] == 'S') ? 'W' : 'S';
    }
  }
  if (T[0] != T.back()) return false;
  if ((S[0] == 'o' && T[0] == 'S') || (S[0] == 'x' && T[0] == 'W')) {
    if (T[1] != T[N - 1]) return false;
  } else {
    if (T[1] == T[N - 1]) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  string S;
  cin >> S;

  const vector<string> pattern = {"SS", "SW", "WS", "WW"};
  rep(i, (int)pattern.size()) {
    string answer = pattern[i];
    if (getAnswer(S, answer)) {
      cout << answer.substr(0, N) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
