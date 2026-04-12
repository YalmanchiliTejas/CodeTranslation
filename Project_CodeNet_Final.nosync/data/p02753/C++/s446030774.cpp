#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define FASTIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int N = 100005, M = 1000000007, BIG = 0x3f3f3f3f;

int n;
string s;

void Process() {
  n = s.length();
  bool a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A')
      a = 1;
    else
      b = 1;
  }
  if (a && b)
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main() {
  FASTIO();

  while (cin >> s) {
    Process();

    if (cin.eof())
      break;
  }

  return 0;
}