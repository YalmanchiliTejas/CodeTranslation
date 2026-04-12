#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int h[n];
  
  int max=0; int count=0;
  for(int i=0; i<n; i++){
    cin >> h[i];
    if(h[i]>=max){
      count++;
      max = h[i];
    }
  }
  
  cout << count;
  
  return 0;
}