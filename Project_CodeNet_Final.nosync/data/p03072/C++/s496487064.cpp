#include<iostream>
 
using namespace std;
 
int main(){
  int N;
  cin >> N;
  
  int H[N];
  for(int i = 0; i < N; i++) cin >> H[i];
  
  int MAX = 0;
  int cnt = 0;
  
  for(int i = 0; i < N; i++){
    if( MAX <= H[i] ){
      MAX = H[i];
      cnt++;
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}