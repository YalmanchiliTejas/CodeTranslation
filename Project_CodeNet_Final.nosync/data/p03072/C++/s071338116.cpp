#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
  int n,max = 0,maxcount = 0;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
    if(max <= h[i]){
      max = h[i];
      maxcount++;
    }
  }
  cout << maxcount << endl;
  return 0;
}