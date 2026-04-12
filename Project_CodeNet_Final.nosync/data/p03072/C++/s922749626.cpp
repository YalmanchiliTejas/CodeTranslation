#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s = 1;
  cin >> n;
  vector<int> v(n);
  cin >> v.at(0);
  for(int i = 1; i < n; i++){
    cin >> v.at(i);
    bool a = 1;
    for(int j = 0; j < i; j++){
      if(v.at(i) < v.at(j))
        a = 0;
    }
    if(a)
      s++;
  }
  cout << s << endl;
}