#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  int h[n];
  int m =0,ret=0;
  for(int i=0;i<n;i++){
    cin >> h[i];
    if(m<=h[i])ret++;
    m = max(m,h[i]);
  }
  cout << ret << endl;
  return 0;
}