#include<bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, ans;
  cin >> n;
  ans = n * 800 - (n / 15) * 200;
  cout << ans << "\n";
}