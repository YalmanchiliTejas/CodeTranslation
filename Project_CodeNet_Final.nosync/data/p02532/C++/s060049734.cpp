#include <bits/stdc++.h>
using namespace std;
  
// #define int long long
#define pb push_back
#define print(Target) cout << Target << '\n'

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPS(i, a, n) for (int i = (a); i < (n); i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

bool is_uruu(int y) {return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));}

signed main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<stack<char> > block(n);
  string s;

  while (cin >> s, s != "quit"){
    if (s == "push"){
      int p;
      char c;
      cin >> p >> c;
      block[p - 1].push(c);
    }
    else if (s == "pop"){
      int p;
      cin >> p;
      print(block[p - 1].top());
      block[p - 1].pop();
    }
    else {
      int p, q;
      cin >> p >> q;
      block[q - 1].push(block[p - 1].top());
      block[p - 1].pop();
    }
  }

  return (0);
}