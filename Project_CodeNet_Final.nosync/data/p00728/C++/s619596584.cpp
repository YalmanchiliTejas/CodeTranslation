#include <iostream>
using namespace std;

int main(){
  int a[101];
  int b[20];
  int n = 0;
  int i = 0;
  int max = 0;
  int min = 1000;
  int sum = 0;
  int counter = 0;
  while(1){
    max = 0;
    min = 1000;
    sum = 0;
    cin >> n;
    if(n==0) break;
    for(i=0;i<n;i++){
      cin >> a[i];
      if(max <= a[i]) max = a[i];
      if(min >= a[i]) min = a[i];
      sum += a[i];
    }
    b[counter] = (sum - max - min) / (n - 2);
    counter++;
  }
  for(i=0;i<counter;i++){
    cout << b[i] << endl;
  }
  return 0;
}