#include<iostream>
using namespace std;

int main(){
  int n, i=0, a[5], min, aaa, b, c;
  while(cin >> n){
    a[i] = n;
    i++;
  }

  min = a[0] * a[3] + a[1] * a[4];
  for(i=1;i<=100000;i++){
    if(a[3] - i >= 0){
      b = a[3] - i;
    }
    else{
      b = 0;
    }
    if(a[4] - i >= 0){
      c = a[4] - i;
    }
    else{
      c = 0;
    }
    aaa = a[2] * 2 * i + a[0] * b + a[1] * c;
    if(aaa < min)min = aaa;
  }
  cout << min << endl;
  return 0;
}
