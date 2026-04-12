#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (n % 2 == 0){
    for (int i = 0; i < n / 2; i++){
      cout << a[n - 1 - i * 2] << ' ';
    }
    for (int i = n / 2; i < n; i++){
      cout << a[(i - n / 2) * 2];
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  } else {
    for (int i = 0; i < n / 2 + 1; i++){
      cout << a[n - 1 - i * 2] << ' ';
    }
    for (int i = n / 2 + 1; i < n; i++){
      cout << a[(i - (n / 2 + 1)) * 2 + 1];
      if (i < n - 1){
        cout << ' ';
      }
      cout << endl;
    }
  }
}