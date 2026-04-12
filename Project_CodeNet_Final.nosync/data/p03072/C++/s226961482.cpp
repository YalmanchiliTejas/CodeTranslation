#include <bits/stdc++.h>
using namespace std;
const int maxN = 20;
int n, h[maxN], res(0);
bool c;
int main(){
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> h[i];
  for (int i = 0; i < n; ++i){
    c = true;
    for (int j = 0; j <= i; ++j){
      if (h[j] > h[i]) c = false;
    }
    res += c;
  }
  cout << res;
}
