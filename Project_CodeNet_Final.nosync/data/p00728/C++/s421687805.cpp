#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n, sum, ave;
  while (cin >> n) {
    vector<int> vec(n);
    for (int i=0; i < vec.size(); i++) {
      cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    if (vec.size() > 2) {
      for (int i=1; i<n-1; i++) {
        sum += vec[i];
      }
      ave = sum / (n-2);
    cout << ave << endl;
    }
    sum = 0;
    ave = 0;

  }
}
