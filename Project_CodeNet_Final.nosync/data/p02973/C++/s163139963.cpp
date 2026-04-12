#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n; cin >> n;
  vector<int> v;
  rep(i, n){
    int x; cin >> x;
    auto it = lower_bound(v.begin(), v.end(), x);
    if(it == v.begin()){
      v.insert(v.begin(), x);
    }
    else{
      it--;
      *it = x;
    }
    /*rep(j, v.size()){
      cout << v[j] << " ";
    }
    cout << endl;*/
  }
  cout << v.size() << endl;
  return 0;
}
