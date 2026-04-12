#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define veci(x,n) vector<int> x((int) (n))
#define vecs(x,n) vector<string> x((int) (n))
#define vecbf(x,n) vector<bool> x((int) (n), false)

int main(){
  int n;
  cin >> n;
  veci(h,n);
  rep(i,n) cin >> h.at(i);
  int count = 0;
  bool flag = true;
  rep(i,n){
    for(int j=0;j<i;j++){
      flag = true;
      if(h.at(j) > h.at(i)){
        flag = false;
        break;
      }
    }
    if(flag) count++;
  }
  cout << count << endl;
}