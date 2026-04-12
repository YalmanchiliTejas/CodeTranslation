#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e5+5, LG = 17, MOD = 998244353;
const int SQ = 450;
const long double EPS = 1e-7;

int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
  int mx = 0;
  int ans = 0;
  int n, x;
  cin >> n;
  vector<int> a(n);
  for(auto & x : a) cin >> x;
  reverse(a.begin(),a.end());
  multiset<int>st;
  for(auto x : a){
    auto it = st.upper_bound(x);
    if(it!=st.end())st.erase(it);
    st.insert(x);
  }
  cout<<st.size()<<endl;


  return 0;
}
