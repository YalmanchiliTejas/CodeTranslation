#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  int count=1;
  int max = h[0];
  for(int j = 1; j < n; j++) {
    if(max <= h[j]){
      count++;
      max = h[j];
    }
  }
  cout << count;
  return 0;
}
