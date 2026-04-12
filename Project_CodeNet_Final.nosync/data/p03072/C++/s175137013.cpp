#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int i,j;
  cin >> n;
  vector<int> h(n);
  for(auto& e : h) cin >> e;
  int counter = 0;
  int hMax = h[0];
  for(i=0; i<n; ++i){
    if(hMax <= h[i]){
      counter++;
      hMax = h[i];
    }
  }
  cout << counter << endl;
  return 0;
}
