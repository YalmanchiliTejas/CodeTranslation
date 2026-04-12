#include <iostream>
#include <vector>
#include <string>
#include <cfenv>
#include <cmath>
#include <string>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  rep(i,s.size()-1){
    if(s[i] != s[i+1]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return  0;
}
