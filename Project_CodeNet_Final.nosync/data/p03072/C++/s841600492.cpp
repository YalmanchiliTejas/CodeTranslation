#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n){cin >> h[i];}
  
  int niceView = 1; //西端は常に見られる
  int maxHeight = h.at(0);
  for(int i=1;i<n;i++){
    if(maxHeight <= h.at(i)){
      maxHeight = h.at(i);
      niceView++;
    }
  }
  cout << niceView << endl;
}