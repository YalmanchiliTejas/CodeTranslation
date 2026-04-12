#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define INF 1100000000
#define LLINF 1100000000000000000
#define MOD 1000000007
#define FI first
#define SE second
#define MP make_pair

using namespace std;
typedef long long ll;

int main()
{
  int n; cin >> n;
  int alf[26] = {};
  REP(i, 26) alf[i] = INF;
  REP(i, n) {
    string S;
    cin >> S;
    int tmp[26] = { };
    REP(i, S.size()) tmp[S[i] - 'a']++;
    REP(i, 26) alf[i] = min(alf[i], tmp[i]);
  }
  REP(i, 26) {
    REP(j, alf[i]) cout << (char)(i + 'a');
  }
  cout << endl;

  return 0;
}