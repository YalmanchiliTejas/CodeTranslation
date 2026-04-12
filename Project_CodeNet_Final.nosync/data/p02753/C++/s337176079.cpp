#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
  string s;
  cin >> s;
  rep(i,2){
    if(s.at(i) != s.at(i+1)){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}

