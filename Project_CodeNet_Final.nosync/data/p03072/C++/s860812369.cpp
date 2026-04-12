#include<iostream>
using namespace std;

int main(){
  int N;
  int sum=0;
  int H[100]={};
  cin >> N;
  int max_temp = 0;
  for(int i=0; i<N; i++){
    cin >> H[i];
      
    if(i==0) {
      max_temp = H[0];
      sum++;
    }else{
      if(max_temp <= H[i]){
	sum++;
	max_temp = H[i];
      }
    }
  }
  cout << sum <<endl;
  return 0;
}
