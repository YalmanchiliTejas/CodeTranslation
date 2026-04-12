#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  deque<int> d;
  for (int i = 0; i < n; i++) {
    int p = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
    if(p == 0){
      d.push_front(v[i]);
    }else d[p-1] = v[i];
  }
  int res = d.size();
  cout << res << endl;
}
