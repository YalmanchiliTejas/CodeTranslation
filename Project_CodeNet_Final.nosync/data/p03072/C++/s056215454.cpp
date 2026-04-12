#include <iostream>
using namespace std;
int N, H[100];
main(void){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
  int r=0;
  for(int i=0; i<N; i++){
    bool flag = true;
    for(int j=0; j<i; j++){
      if(H[j]>H[i]){
        flag=false;break;
      }
    }
    if(flag)r+=1;
  }
  cout << r << endl;
}