#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int ans = 800 * n;
  int number = n / 15;
  int discount = 200 * number;
  
  cout << ans - discount << endl;
  return 0;
}