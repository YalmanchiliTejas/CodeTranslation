#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int N;
  cin >> N;
  map<char, int> A{};
  {
    string S;
    cin >> S;
    REP(i, S.size()) { A[S[i]]++; }
  }
  REP(i, N - 1) {
    map<char, int> B{};
    string S;
    cin >> S;
    REP(j, S.size()) { B[S[j]]++; }
    REP(j, 26) {
      char a = j + 'a';
      A[a] = min(A[a], B[a]);
    }
  }
  REP(i, 26) {
    char a = i + 'a';
    REP(j, A[a]) { cout << a; }
  }
  cout << endl;
}