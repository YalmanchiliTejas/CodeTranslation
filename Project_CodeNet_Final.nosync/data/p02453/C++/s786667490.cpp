#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) {
      cin >> v[i];
  }
  int q;
  cin >> q;
  vector<int> vc(q);
  for(int i=0; i<q; i++) {
      cin >> vc[i];
  }
  for(int i=0; i<q; i++) {
      cout << (lower_bound(v.begin(),v.end(),vc[i])-v.begin()) << endl;
  }
}
