#include <bits/stdc++.h>
using namespace std;


int main() {
  int n; cin >> n;
  int cnt = 0;
  vector<int> mt(n);
  for(int i = 0; i < n; i++){
    cin >> mt[i];
  }
  int v = -1;
  for(int i = 0; i < n; i++){
    if(mt[i] >= v){
      cnt++;
    }
    v = max(v,mt[i]);
  }
  cout << cnt << endl;
}