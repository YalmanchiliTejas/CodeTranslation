#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  string S; cin >> S;
  cout << (S.find("AC") != string::npos ? "Yes" : "No") << endl;
}