#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) {
    cin >> vec.at(i);
  }
  int max=0;
  int num=1;
  rep(i,n){
    if (i==0) {
      max = vec.at(i);
      continue;
    }
    if (vec.at(i)>=max){
      max=vec.at(i);
      num++;
    }
  }
  cout << num << endl;
}