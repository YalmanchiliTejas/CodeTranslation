#include<iostream>
using namespace std;
int main(){
  int N, AM = 0, count = 0;
  int A[21];
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(AM <= A[i]){
      AM =A[i];
      ++count;
    }
  }
  cout << count << endl;
    return 0;
}