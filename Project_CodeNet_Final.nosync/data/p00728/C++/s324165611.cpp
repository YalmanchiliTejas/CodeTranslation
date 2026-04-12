#include <iostream>
using namespace std;

int main(){
  int n, s, sum, max, min;
  while(1){
    cin >> n;
    if(n == 0) break;
    sum = 0;
    cin >> s;
    sum += s;
    max = s;
    min = s;
    cin >> s;
    sum += s;
    if(max < s){
      max = s;
    }else{
      min = s;
    }
    for(int i = 2; i < n; i++){
      cin >> s;
      sum += s;
      if(max < s){
	max = s;
      }else if(min > s){
	min = s;
      }
    }
    sum -= max;
    sum -= min;
    int ave = sum / (n-2);

    cout << ave << endl;
  }

  return 0;
}