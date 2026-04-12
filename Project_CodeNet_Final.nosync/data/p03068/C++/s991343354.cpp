#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >>s;
  int k;
  cin >>k;
  int tmp = s.at(k-1);
  for (int i = 0; i < n; i++) {
    if(s.at(i) != tmp) {
      s.at(i) = '*';
    }
  }
  
  cout << s << endl;
}