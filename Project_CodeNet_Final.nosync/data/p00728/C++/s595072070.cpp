#include <iostream>
#include <vector>
using namespace std;

int main(){

  int n, s,  min, max;
  int total;
  while(cin >> n){
    total = 0;

   if(n == 0) break;

    for(int i=0; i<n; i++){
      cin >> s;
      if(i == 0){
	min = s;
	max = s;
      }
      if(s < min) min = s;
      if(s > max) max = s;
      total += s;
    }
    cout << (total-min-max)/(n-2) << endl; 
  }
  return 0;
}