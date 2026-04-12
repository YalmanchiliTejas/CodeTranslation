#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n){
    cin >> vec.at(i);
  }

  int high=0;
  int sum = 0;
  rep(i,n){
    if (vec.at(i) >= high){
      sum ++;
      high = max(high,vec.at(i));
    }
  }
  
  cout << sum << endl;
}