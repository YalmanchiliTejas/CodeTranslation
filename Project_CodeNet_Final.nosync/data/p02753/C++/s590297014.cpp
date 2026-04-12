#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return b/gcd(a,b)*b;}

int main() {
  set<char> st;
  rep(i, 3) {
    char c;
    cin >> c;
    st.insert(c);  
  }
  if (st.size() == 1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}