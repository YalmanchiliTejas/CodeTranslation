// https://atcoder.jp/contests/abc134/tasks/abc134_e

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
#define DUMP2D(a) REP(_i, a.size()) DUMP(a[_i]); cout << endl

const int N_MAX = 1e5;
const int A_I_MAX = 1e9;

int N;
vector<int> A;

int main() {
  cin >> N;
  A = vector<int>(N);
  REP(i, N) cin >> A[i];

  multiset<int> st;
  REP(i, N) {
    auto it = st.lower_bound(A[i]);
    if (it != st.begin()) st.erase(--it);
    st.insert(A[i]);
  }

  int ans = st.size();
  cout << ans << endl;
}
