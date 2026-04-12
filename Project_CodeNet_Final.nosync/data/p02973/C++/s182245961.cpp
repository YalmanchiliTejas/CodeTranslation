#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> ans(0);
  for(int i=0; i<n; ++i){
    int x;
    cin >> x;
    if(i == 0 || x <= ans[ans.size()-1]){
      ans.push_back(x);
      continue;
    }
    int l=-1, r=ans.size()-1;
    while(l+1 < r){
      int mid = (l+r)/2;
      if(ans[mid] >= x) l = mid;
      else r = mid;
    }
    ans[r] = x;
  }
  cout << ans.size() << endl;
}