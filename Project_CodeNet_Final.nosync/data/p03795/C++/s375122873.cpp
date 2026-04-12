#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main() {
  int N;
  cin >> N;
  int x = N*800;
  int y = N/15*200;
  int ans = x-y;
  cout << ans << endl;
} 