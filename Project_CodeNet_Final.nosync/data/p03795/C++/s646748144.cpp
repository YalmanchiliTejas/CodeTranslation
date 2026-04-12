#include<iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int ans = n/15;
  ans *= -200;
  ans += n*800;
  cout << ans << endl;
  
  return 0;
  }