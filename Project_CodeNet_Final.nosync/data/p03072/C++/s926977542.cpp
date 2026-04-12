#include <iostream>
using namespace std;

int main(){
  int n, count, max;
  int h[150];
  cin >> n;
  for (int i = 0; i < n; i++){
  cin >> h[i];
  }
  count = 0;
  max = -100;
  for (int j = 0; j < n; j++){
  if (h[j] >= max){
    max = h[j];
  count++;
  }else{
  continue;
  }
  }
  cout << count << endl;
}