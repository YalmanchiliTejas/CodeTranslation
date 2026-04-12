#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>

using namespace std;
int main(){
  long long n;
  cin >> n;

  vector<vector<int>> cnt(n, vector<int>(26, 0));
  vector<string> s(n);

  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < s[i].size(); j++){
      cnt[i][s[i][j] - 'a']++;
    }
  }
  
//  for(int i = 0; i < n; i++){
//    for(int j = 0; j < 26; j++){
//      cout << cnt[i][j] << " ";
//    }
//    cout << endl;
//  }
//  cout << endl;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 26; j++){
      cnt[0][j] = min(cnt[0][j], cnt[i][j]);
    }
  }

//  for(int i = 0; i < n; i++){
//    for(int j = 0; j < 26; j++){
//      cout << cnt[i][j] << " ";
//    }
//    cout << endl;
//  }
//  cout << endl;

  
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < cnt[0][i]; j++){
      cout << (char)(i+'a');
    }
  }
  cout << endl;

  return 0;
} 
