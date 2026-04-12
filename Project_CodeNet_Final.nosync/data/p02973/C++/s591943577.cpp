#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i, n) {
    cin >> a[i];
    a[i] *= -1;
  }
  vector<int> s;
  rep(i, n){
    int p = lower_bound(s.begin(), s.end(), a[i]+1) - s.begin();
    if(p == s.size()) s.push_back(a[i]);
    else s[p] = a[i];
  }
  cout << s.size() << endl;
  return 0;
}
