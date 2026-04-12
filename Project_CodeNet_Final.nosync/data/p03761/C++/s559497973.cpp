// 

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <stack>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
  int n;
  string s[55];
  int data[55][26];
  for(int i = 0; i < 55; i++){
    for(int k = 0; k < 26; k++){
      data[i][k] = 0;
    }
  }
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i];

    int len = s[i].length();
    for(int k = 0; k < len; k++){
      data[i][s[i][k] - 'a']++;
    }
  }

  for(int k = 0; k < 26; k++){
    int sum = 100;
    for(int i = 0; i < n; i++){
      sum = min(sum, data[i][k]);
    }
    for(int i = 0; i < sum; i++){
      cout << char(k + 'a');
    }
  }
  cout << endl;
  return 0;
}
