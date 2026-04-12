#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

int main() {
  int n;
  string *S;
  cin >> n;
  S = new string[n];
  REP(i, n) {
    cin >> S[i];
  }

  map<char, int> m, m_temp;

  REP(i, n) {
    if (i == 0) {
      for(auto c:S[i]) {
        m[c] += 1;
      }
      continue;
    } else {
      for(auto c:S[i]) {
        m_temp[c] += 1;
      }
      for(auto p:m_temp) {
        char c = p.first;
        if (m[c] > m_temp[c]) { m[c] = m_temp[c]; }
      }
      for(auto p:m) {
        char c = p.first;
        if (m[c] > m_temp[c]) { m[c] = m_temp[c]; }
      }
      m_temp.clear();
    }
  }

  string result;
  for (auto p:m) {
    REP(i, p.second) { result.push_back(p.first); }
  }
  sort(ALL(result));

  cout << result << endl;
  
  return 0;
}