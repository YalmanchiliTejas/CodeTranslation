#include <bits/stdc++.h>

using namespace std;

int main(){
  int N;;
  while(1){
    cin >> N;
    if(N == 0){
      break;
    }else{
      int array[N], ave, sum = 0;
      
      for(int i = 0;i < N;i++){
	cin >>array[i];
      }
      sort(array,array+N);
      for(int i = 0;i < N;i++){
	if(!(i == 0 || i == N-1)){
	sum += array[i];
	}
      }
      ave = sum /( N -2);
      cout << ave << endl;
      
    }
  }
  
  return 0;
}

