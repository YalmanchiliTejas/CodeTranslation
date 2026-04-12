#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define rev(i,s,e) for(i64 (i) = (s);(i) --> (e);)
#define all(x) x.begin(),x.end()

int main() {
  i64 N;
  cin >> N;
  vector<i64> A(N);
  rep(i,0,N) cin >> A[i];

  multiset<i64> st;
  st.insert(A[0]);
  rep(i,1,N) {
    auto iter = st.lower_bound(A[i]);
    if(iter != st.begin()) {
      --iter;
      st.erase(iter);
    }
    st.insert(A[i]);
  }
  cout << st.size() << endl;
}
