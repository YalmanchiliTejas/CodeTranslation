#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int m=0, cnt=0;
  for(int i=0; i<n; i++){
    int h;
    cin >> h;
    if(h>=m){
      cnt++;
      m=h;
    }
  }
  cout << cnt;
  return 0;
}