#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int n, m, count;
  count = 0;
  m = 0;
  cin >> n;
  int h[n];
  for(int i=0; i<n; i++){
    cin >> h[i];
    if(m < h[i]+1){
      count += 1;
      m = h[i];
    
    }
  }
  cout << count << endl;
}

