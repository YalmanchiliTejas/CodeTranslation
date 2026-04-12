#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int max_H = 0, ans = 0;
  for(int i = 0;i < N;i++){
    int H;
    cin >> H;
    
    if(max_H <= H){
      max_H = H;
      ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}