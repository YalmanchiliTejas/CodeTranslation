#include <iostream>
#include <random>
using namespace std;

int main(){
  int N,max = 0,cnt = 0;
  int H[100] = {0};
    cin >> N;
  for(int i = 0;i<N;i++){
    cin >> H[i];
  }
  
  for(int i = 0;i < N;i++){
  if(max<=H[i]){
    max = H[i];
    cnt++;
  }
  }

  cout << cnt << endl;

}