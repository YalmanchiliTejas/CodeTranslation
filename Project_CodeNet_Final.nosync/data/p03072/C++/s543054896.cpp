#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int now, seeable=0, highest=0;
  for(int i=0; i<N; i++){
    cin >> now;
    if(highest <= now){
      seeable++;
      highest=now;
    }
  }
  
  cout << seeable;
}