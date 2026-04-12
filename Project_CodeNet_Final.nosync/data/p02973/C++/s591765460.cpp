#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
typedef long long ll;

void dump(vector<int> &data, string name) {
  cout << name << "= { ";
  for(int i = 0; i<data.size(); i++)
    cout << data[i] << " ";
  cout << "} " << endl;
}

int main() {
  int n;
  cin >> n;
  vector <ll> a(n);
  rep(i,n) cin >> a[i];
  vector<int> v;
  v.push_back(a[n-1]);
  for(int i=n-2; i>=0; i--){
    auto p = upper_bound(v.begin(), v.end(), a[i]);
    auto id = distance(v.begin(), p);
    if(id == v.size())
      v.push_back(a[i]);
    else {
      v[id] = a[i];
    }
  }    
  cout << v.size() << endl; 
  return 0;
}
