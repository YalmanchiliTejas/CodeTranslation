#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, a;
  cin >> n;
  int count = 0;
  int max = 0;
  for(int i=0; i<n; i++) {
    cin >> a;
    if(max <= a) {
      count++;
      max = a;
    }
  }
  cout << count << endl;
}