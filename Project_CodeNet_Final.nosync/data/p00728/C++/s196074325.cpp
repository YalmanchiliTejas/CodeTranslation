#include <iostream>
using namespace std;
int N, S;
int main(){
  while (cin >> N && N > 0) {
    int sum = 0;
    int max = 0;
    int min = 1000000000;
    for(int i = 0 ; i < N ; i++){
      cin >> S;
      sum += S;
      if(S > max){
	max = S;
      }
      if(S < min){
	min = S;
      }
    }
    cout << (sum-max-min)/(N-2) << endl;
    //cout << "max:" << max << endl;
    //cout << "min:" << min << endl;
  }
}