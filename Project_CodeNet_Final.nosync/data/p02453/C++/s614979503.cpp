#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  int q;  cin >> q;
  for(int i=0; i<q; i++){
    int k; cin >> k;
    auto itr = lower_bound(a.begin(),a.end(),k);
    
    cout << itr-a.begin() << endl;
  }

}
