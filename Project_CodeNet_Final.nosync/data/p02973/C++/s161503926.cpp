#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  multiset<int> st;

  for (int i = 0; i < n; i++) {
    auto itr = st.upper_bound(-a[i]);
    if (itr == st.end()) st.insert(-a[i]);
    else {
      st.erase(itr);
      st.insert(-a[i]);
    }
  }
  cout << st.size() << endl;
  return 0;
} 