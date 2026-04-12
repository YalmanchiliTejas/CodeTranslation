#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,ans,coupon;
  cin >> N;
  coupon = N/15;
  ans = 800*N - 200*coupon;
  cout << ans <<endl;
  return 0;
}
