#include <iostream>
#include <string>

using namespace std;



int main(void) {
  
  int N;
  
  cin >> N;
  
  int *H = new int[N];
  
  for(int ii = 0;ii < N; ii++) {
    cin >> H[ii];
  }
  
  int NotLookFlag = 0;
  int canLookFlag = 1;
  for(int jj = 1; jj < N;jj++) {
    NotLookFlag = 0;
    for(int kk = 0;kk < jj; kk++) {
      if(H[kk] > H[jj]) {
        NotLookFlag++;
      }
    }
    if(NotLookFlag == 0 ) {
      canLookFlag++;
    }
  }
  
  printf("%d", canLookFlag);
  
  return 0;
}