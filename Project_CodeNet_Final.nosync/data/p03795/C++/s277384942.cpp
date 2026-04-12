#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;

  int survice = n / 15;
  int price = n * 800 - survice * 200;
  
  cout << price << endl;
}