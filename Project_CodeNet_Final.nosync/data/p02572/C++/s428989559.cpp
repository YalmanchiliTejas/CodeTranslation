#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >>n;
  vector<int> a(n);
  int64_t sum=0;
  rep(i,n) {
    cin >> a[i];
    sum+=ll(a[i]);
  }
  int64_t res=0;
  rep(i,n-1){
    sum-=ll(a[i]);
    res+=int64_t(sum%(1000000007))*int64_t(a[i]);
    res=res%(1000000007);
  }
  cout << res <<endl;
}
