#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;
int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
  multiset<int> s;
  cin>>n;
  for (int i=0; i<n; i++) {
    int x; cin>>x;
    if (s.empty() || *s.begin() >= x) {
      s.insert(x);
    } else {
      auto iter = s.lower_bound(x);
      --iter;
      s.insert(x);
      s.erase(iter);
    }
  }

  cout<<s.size()<<endl;
  

  return 0;
}
