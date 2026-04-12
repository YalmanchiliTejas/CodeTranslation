#include<iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int m=0;
  for(int i=1; i <= N; i++){
    if(i%15==0){
      m+=800-200;
    }else{
      m+=800;
    }
  }
  cout << m << endl;
  return 0;
}