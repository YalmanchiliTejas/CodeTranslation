#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s; cin>>s;
  set<char> st;
  st.insert(s[0]); st.insert(s[1]);
  st.insert(s[2]);
  if (st.size() == 2) out("Yes");
  out("No");
  
  

  return 0;
}
// don't forget to read in the input :^)
