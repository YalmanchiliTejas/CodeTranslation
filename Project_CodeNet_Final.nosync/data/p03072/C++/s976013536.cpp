#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h.at(i);

  int sum = 1;
  int max = h.at(0);
  for(int i=1;i<n;i++){
    if((max <= h.at(i)) && (h.at(i-1) <= h.at(i))){
      sum++;
      max = h.at(i);
    }
  }
  cout << sum << endl;
  return 0;
}
