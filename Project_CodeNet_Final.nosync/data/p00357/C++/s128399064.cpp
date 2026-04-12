#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int* A = new int[N];
  
  for(int i = 0; i < N; i++)cin >> A[i]; 
  int max = A[0];
  for(int i = 1; i < N; i++){
    if(max < 10){
      cout << "no" << endl;
      return 0;
    }  
    max -= 10;
    if(max < A[i]){
      max = A[i];
    
    }
  }
    max = A[N-1];
 
    for(int i = N-2; i>=0; i--){
    
      if(max < 10){
        cout << "no" << endl;
        return 0;
      }  
      max -= 10;
      if(max < A[i]){
        max = A[i];
      }
    }
    cout << "yes" << endl;
  }

