#include <iostream>
#include <deque>
using namespace std;

int main(){

  int n, a;
  deque<int> dp;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(i % 2 == (n-1) % 2) dp.push_front(a);
    else dp.push_back(a);
  }
  for(int i = 0; i < n; i++){
    cout << dp[i] << ((i == n-1) ? "\n" : " ");
  }
  return 0;
}
