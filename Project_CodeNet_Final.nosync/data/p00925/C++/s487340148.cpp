#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <numeric>

#define phb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
const ll kInf = 1000000000;

string S;
ll T;
vector< ll > rn;
vector< char > rt;

void solve();
bool rule1();
bool rule2();

int main() {
  cin >> S >> T;
  solve();
  return 0;
}

void solve() {
  bool bb, bc;

  for (int i = 0; i < sz(S); ++i)
    if (!isdigit(S[i]))
      rt.phb(S[i]), S[i] = ' ';

  istringstream iss(S);
  ll tn;
  while (iss >> tn)
    rn.phb(tn);

  bb = rule1();
  bc = rule2();

  if (bb)
    cout << (bc ? "U" : "M") << "\n";
  else
    cout << (bc ? "L" : "I") << "\n";
}

bool rule1() {
  vector< ll > nrn;

  nrn.phb(rn[0]);
  for (int i = 0; i < sz(rt); ++i) {
    if (rt[i] == '+')
      nrn.phb(rn[i + 1]);
    else {
      nrn.back() *= rn[i + 1];
      if (nrn.back() >= kInf)
        return false;
    }
  }

  return accumulate(all(nrn), ll(0)) == T;
}

bool rule2() {
  ll tmp = rn[0];

  for (int i = 0; i < sz(rt); ++i) {
    if (rt[i] == '+')
      tmp += rn[i + 1];
    else
      tmp *= rn[i + 1];

    if (tmp >= kInf)
      return false;
  }

  return tmp == T;
}