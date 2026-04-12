#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int kazu = 0;
  cin >> kazu;
  vector<vector<int>> count(kazu,vector<int>(26));
  for(int i = 0;i <= kazu - 1;i++){
    for(int j = 0;j <= 25;j++){
      count[i][j] = 0;
    }
  }
  //cout<<0<<endl;
  for(int i = 0;i <= kazu - 1;i++){
    string str;
    cin >> str;
    for(int j = 0;j <= str.size() - 1;j++){
      count[i][str[j] - 'a']++;
    }
  }
  //cout<<1<<endl;
  for(int i = 0;i <= 25;i++){
    int res = 0;
    res = INT_MAX;
    for(int j = 0;j <= kazu - 1;j++){
      res = min(res,count[j][i]);
    }
    for(int j = 0;j <= res - 1;j++){
      cout << (char)('a' + i);
    }
  }
  cout << endl;
  return 0;
}