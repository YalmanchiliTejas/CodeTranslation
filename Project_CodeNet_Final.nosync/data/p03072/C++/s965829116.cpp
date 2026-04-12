#include <iostream>
using namespace std;

int main(){
  int N;
  int A[30];

  cin >> N;
  for(int i=0; i<N; i++)  cin >> A[i];

  int ans = 1;
  int hi = A[0];

  for(int i=1; i<N; i++){
    if(hi<=A[i]){
      ans += 1;
      hi = A[i];
    }
  }

  cout << ans << endl;
}
