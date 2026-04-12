#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int A[12];
  for(int i = 0; i < 12; i++){
    cin >> A[i];
  }
  sort(A, A+12);

  if(A[0] == A[3] && A[4] == A[7] && A[8] == A[11]){
    cout << "yes\n";
  }else{
    cout << "no\n";
  }

  return 0;
}