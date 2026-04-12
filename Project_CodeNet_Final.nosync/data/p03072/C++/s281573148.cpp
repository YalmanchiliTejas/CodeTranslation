#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> h(n);
  rep(i,n){
    cin >> h[i];
  }
  int64_t hmax = 0;
  int64_t cnt = 0;
  rep(i,n){
    if(hmax <= h[i]){
      hmax = h[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}
    
    
