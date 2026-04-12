#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  int n;
  int i,j;
  cin >> n;
  vector<int> h(n);
  for(i=0; i<n; i++){
    cin >> h[i];
  }
  int counter = 1;
  for(i=1; i<n; i++){
    for(j=0; j<i; j++){
      if(h[i]<h[j]){
        break;
      }
      if(j==i-1){
        counter++;
      }
    }
  }
  cout << counter << endl;
  // end process
  return 0;
}
