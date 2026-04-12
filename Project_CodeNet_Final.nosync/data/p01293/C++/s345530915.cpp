#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int f(char a) {
  if (a == 'T') return 10;
  if (a == 'J') return 11;
  if (a == 'Q') return 12;
  if (a == 'K') return 13;
  if (a == 'A') return 14;
  return a - '0';
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  char tr;
  while (cin >> tr, tr != '#') {
    vector<vector<string>> ca(4, vector<string>(13));
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        cin >> ca[i][j];
      }
    }

    int lead = 0, NS = 0, EW = 0;
    for (int j = 0; j < 13; j++) {
      int next = -1;
      for (int i = 0; i < 4; i++) {
        if (ca[i][j][1] == tr && (next < 0 || f(ca[i][j][0]) > f(ca[next][j][0]))) next = i;
      }
      if (next < 0) {
        for (int i = 0; i < 4; i++) {
          if (ca[i][j][1] == ca[lead][j][1] && (next < 0 || f(ca[i][j][0]) > f(ca[next][j][0]))) next = i;
        }
      }
      if (next & 1) EW++;
      else NS++;
      lead = next;
    }
    cout << (NS > EW ? "NS" : "EW") << " " << max(NS, EW) - 6 << endl;
  }

  return 0;
}
