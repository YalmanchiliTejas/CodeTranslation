#include <bits/stdc++.h>
#define rep(i, n, k) for(int i=k; i<n; ++i)
using namespace std;

int main(){
  int n, ans = 0, hight = 0;
  cin >> n;
  rep(i, n, 0){
    int a;
    cin >> a;
    if(a >= hight){
      ans++;
      hight = a;
    }
  }
  cout << ans << endl;
}