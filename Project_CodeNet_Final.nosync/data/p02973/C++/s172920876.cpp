#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  multiset<int> st;
  repr(i, N, 0) {
    cin >> A[i];
  }

  for (int i = N-1; i >= 0; --i) {
    auto it = st.upper_bound(A[i]);
    if (it == st.end()) {
      st.insert(A[i]);
    } else {
      st.erase(it);
      st.insert(A[i]);
    }
  }
  cout << st.size() << endl;
}