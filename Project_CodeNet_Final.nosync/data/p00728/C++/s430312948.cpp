#include <iostream>
using namespace std;

int main(){
  int max = 0;
  int min = 0;
  int n = 0;
  int point = 0;
  int sum = 0;
  int summation = 0;

  while(true){
    sum = 0;
    int max = 0;
    int min = 0;
    cin >> n;
    if(n == 0) break;
    //int *s = new int[n];

    for(int i = 0; i < n; i++){
      cin >> point;
      if(i == 0){
        max = point;
        min = point;
      }else{
        if(point >= max) max = point;
        if(point <= min) min = point;
      }
      sum += point;
    }

    summation = sum - max - min;
    cout << summation / (n-2) << "\n";
  }
}

