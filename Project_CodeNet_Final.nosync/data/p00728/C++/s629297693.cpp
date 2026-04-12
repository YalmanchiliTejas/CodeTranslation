#include <bits/stdc++.h>
using namespace std;
int main(){
  while (1){
    int n;
    cin >> n;
    if (n == 0){
      break;
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++){
      cin >> s[i];
    }
    sort(s.begin(), s.end());
    int sum = 0;
    for (int i = 1; i < n - 1; i++){
      sum += s[i];
    }
    cout << sum / (n - 2) << endl;
  }
}
