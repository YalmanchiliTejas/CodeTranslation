#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(a.begin(), a.end());
  vector<int> big, small;
  rep(i, n){
    if(i < (n+1)/2) small.push_back(a.at(i));
    else big.push_back(a.at(i));
  }
  if(n % 2 == 0){
    vector<int> ans;
    rep(i, n){
      if(i % 2 == 0){
        if(i == 0){
          ans.push_back(small.back());
        }else{
          ans.push_back(small.at(i/2-1));
        }
      }else{
        if(i == n-1){
          ans.push_back(big.front());
        }else{
          ans.push_back(big.at(i/2+1));
        }
      }
    }
    ll aa = 0;
    rep(i, n-1) aa += abs(ans.at(i) - ans.at(i+1));
    cout << aa << endl;
  }else{
    int mid1 = small.back();
    vector<int> ans;
    rep(i, n){
      if(i % 2 == 0){
        if(i == 0 || i == n-1){
          ans.push_back(small.back());
          if(i == 0)small.pop_back();
        }else{
          ans.push_back(small.at(i/2-1));
        }
      }else{
        ans.push_back(big.at(i/2));
      }
    }
    ll aa = 0;
    rep(i, n-1) aa += abs(ans.at(i) - ans.at(i+1));

    ans.clear();
    rep(i, n){
      if(i % 2 == 0){
        if(i == 0){
          ans.push_back(mid1);
        }else if(i == n-1){
          ans.push_back(big.at(0));
        }else{
          ans.push_back(big.at(i/2));
        }
      }else{
        ans.push_back(small.at(i/2));
      }
    }
    ll bb = 0;
    rep(i, n-1) bb += abs(ans.at(i) - ans.at(i+1));
    aa = max(aa, bb);
    cout << aa << endl;
  }
  return 0;
}