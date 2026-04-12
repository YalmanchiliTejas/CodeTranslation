#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  int n;
  cin >> n;
  multiset<int> st;
  rep(i,n) {
    int a;
    cin >> a;
    auto itr = st.upper_bound(-a);
    if (itr == st.end()) st.insert(-a);
    else {
      st.erase(itr);
      st.insert(-a);
    }
  }
  cout << st.size() << endl;
  return 0;
} 