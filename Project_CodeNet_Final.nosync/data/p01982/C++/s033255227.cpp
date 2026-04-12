#include <iostream>
using namespace std;
int main(void){
  for(;;){
    int n, l, r;
    cin >> n >> l >> r;
    if(n == 0 && l == 0 && r == 0){return 0;}
    int A[n];
    for(int i = 0 ; i < n ; i++){
      cin >> A[i];
    }
    int cnt = 0;
    for(int year = l ; year <= r ; year++){
      bool find = false;
      for(int i = 0 ; i < n && find == false ; i++){
	if(year % A[i] == 0){
	  // cout << "rules for " << A[i] << endl;
	  find = true;
	  if(i % 2 == 0){cnt++;}
	}
      }
      if(find == false){
	if(n % 2 == 0){cnt++;} 
      }
    }
    cout << cnt << endl;
  }
}
