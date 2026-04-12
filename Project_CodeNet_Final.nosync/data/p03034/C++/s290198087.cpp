#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);
   int n;
   cin >> n;
   vector<ll>s(n);
   ll ans = 0;
   rep(i,n)cin >> s[i];
   for(int sa = 1; sa <= n; sa++){
      ll sum = 0;
      int l = 0;
      int r = n - 1;
      set<int>st;
      while(l < n and r > 0){
         sum += s[l];
         st.insert(l);
         sum += s[r];
         if(st.count(r))break;
         st.insert(r);
         int a = r;
         if(a > sa and n - 1 - a > 0 and (n - 1 - a)%sa == 0){
            ans = max(ans, sum);
         }
         l += sa;
         r -= sa;
      }
   }
   cout << ans << endl;
}
