#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ld = long double; 
int INF = 1e9;

int main(){
  int n;cin >> n;
  vector<int> a(n);
  multiset<int> m;
  rep(i,n) {
    cin >> a[i];
    if(*m.begin() >= a[i] || i == 0) m.insert(a[i]);
    else{
      auto it = m.lower_bound(a[i]);
      m.erase(--it);
      m.insert(a[i]);
    }  
  }
  cout << m.size() << endl;
}
