#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;

int main(){
  string s;
  cin >> s;
  if((s.at(0) == s.at(1)) && (s.at(1) == s.at(2)))cout <<"No";
  else cout << "Yes";

}
