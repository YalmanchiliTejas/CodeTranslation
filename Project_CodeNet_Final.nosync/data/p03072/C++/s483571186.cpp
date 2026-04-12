#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> h(n+10);
  rep(i,n) cin >> h[i];
  int count = 1;
  for(int i = 1;i < n;++i){
    bool flag = true;
    for(int j = 0;j<i;++j){
      if(h[j] > h[i]){
        flag = false;
        break;
      }
    }
    if(flag) ++count;
  }
  cout << count << endl;
  return 0;
}
