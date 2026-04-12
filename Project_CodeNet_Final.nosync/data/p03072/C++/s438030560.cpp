#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

int main() {
  int n;
  cin >> n;
  VI h(n);
  rep(i,n) cin >> h.at(i);
  int count=0;
  rep(i,n){
    bool high=true;
    rep(j,i){
      if(h.at(j)>h.at(i)){
        high=0;
        break;
      }
    }
      if(high) count++;
  }
  cout << count <<endl;
    
}