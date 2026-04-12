#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  string s;
  cin >> s;
  if (s.find("A") != std::string::npos && s.find("B") != std::string::npos) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
