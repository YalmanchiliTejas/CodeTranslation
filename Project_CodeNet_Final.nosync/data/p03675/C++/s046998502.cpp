#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector <int> b;
  if(n % 2 == 0) {
    for(int i = 0; i < n; i++) {
      if(i % 2 == 0) {
	b.push_back(a[i]);
      }
      else {
	b.insert(b.begin(), a[i]);
      }
    }
  }
  else {
    for(int i = 0; i < n; i++) {
      if(i % 2 != 0) {
	b.push_back(a[i]);
      }
      else {
	b.insert(b.begin(), a[i]);
      }
    }
  }

  string s;
  for(int i = 0; i < n; i++) {
    s += to_string(b[i]);
    s += " ";
  }
  s.pop_back();
  cout << s << endl;
}