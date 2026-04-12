#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
  int n;
  cin >> n;
  // vector<string> S(n);
  vector<int> min_count(26, 100);
  for(int i=0;i<n;++i){
    string S;
    cin >> S;
    
    vector<int> count(26, 0);
    for(auto c: S){
      count[c - 'a'] ++;
    }
    for (int j=0;j<26;++j){
      min_count[j] = min(min_count[j], count[j]);
    }
  }
  for (int j=0;j<26;++j){
    char c = 'a' + j;
    for (int k=0; k<min_count[j]; ++k){
      cout << c;
    }
  }
}
