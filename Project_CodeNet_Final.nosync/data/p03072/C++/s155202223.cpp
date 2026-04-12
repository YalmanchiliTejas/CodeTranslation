#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;
int ans,n,hi;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n;
  for (int i=0; i<n; i++) {
    int x; cin>>x;
    ans += x>=hi;
    hi=max(x,hi);
  }
  cout<<ans;
  

  return 0;
}
