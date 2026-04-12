// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
*/
#define NONE 0
#define SHEEP 1
#define WOLF 2
int main() {
  int n; in(n);
  string s; in(s);
  char c = s[0];
  
  loop(i,1,3) { // 0番目
    loop(j,1,3) { // 1番目
      vector<int> ans(n+1, NONE);
      ans[0] = i;
      ans[n] = i;
      ans[1] = j;
      if (i == SHEEP and c == 'o') {
        ans[n-1] = j;
      }
      else if (i == SHEEP and c == 'x') {
        ans[n-1] = (j == SHEEP) ? WOLF : SHEEP;
      }
      
      else if (i == WOLF and c == 'x') {
        ans[n-1] = j;
      }
      
      else if (i == WOLF and c == 'o') {
        ans[n-1] = (j == SHEEP) ? WOLF : SHEEP;
      }
      assert(ans[n-1] != NONE);
      
      bool ok = true;
      loop(k,1,n) {
        int k_1 = NONE;
        if (ans[k] == SHEEP and s[k] == 'o') {
          k_1 = ans[k-1];
        } else if (ans[k] == SHEEP and s[k] == 'x') {
          k_1 = ans[k-1] == SHEEP ? WOLF : SHEEP;
        } else if (ans[k] == WOLF and s[k] == 'o') {
          k_1 = ans[k-1] == SHEEP ? WOLF : SHEEP;
        } else if (ans[k] == WOLF and s[k] == 'x') {
          k_1 = ans[k-1];
        }
        assert(k_1 != NONE);
        if (ans[k+1] != NONE and ans[k+1] != k_1) {
          ok = false;
          break;
        }
        ans[k+1] = k_1;
      }
      
      if (ok) {
        loop(i,0,n) {
          if (ans[i] == SHEEP) print('S', "");
          else print('W', "");
        }
        print("");
        return 0;
      }
    }
  }
  
  print(-1);
  return 0;
}
