#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
  int t [50][27] = {};
  int res[27] = {};
  int n;
  string st;
  cin >> n;
  for(int i = 0;i<n;i++){
    cin >> st;
    for(auto c : st) t[i][c - 'a']++;
  }
  fill(res, res+27, 51);
  // for(int i = 0;i < n;i++){
  //   cout << i << ": ";
  //   for(int j = 0;j<27;j++){
  //     cout << t[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for(int i = 0;i<27;i++){
    for(int j = 0;j < n;j++) res[i] = min(t[j][i],res[i]);
  }
  // cout << "   ";
  // for(int i = 0;i<27;i++) cout << res[i] << " ";
  // cout << endl;
  for(int i = 0;i<27;i++){
    for(int j = 0;j<res[i];j++){
      char c = 'a' + i;
      cout << c;
    }
  }
  cout << endl;
  return 0;
}