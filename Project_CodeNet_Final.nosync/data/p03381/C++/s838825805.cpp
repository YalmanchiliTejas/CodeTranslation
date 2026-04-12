#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  int *arr = new int[n];
  int *sorted = new int[n];
  for (int i = 0;i < n;i++){
    cin >> arr[i];
    sorted[i] = arr[i];
  }
  sort(sorted, sorted + n);
  int med1, med2;
  med1 = sorted[n/2 -1];
  med2 = sorted[n/2];
  for (int i = 0; i < n; i++){
    if (arr[i] <= med1){
      cout << med2 << endl;
    }else{
      cout << med1 << endl;
    }
  }
  delete[] arr;
  delete[] sorted;
  return 0;
  
}