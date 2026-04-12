#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, sum;
  sum = 0;
  cin >> N;
  
  for(int i = 1; i <= N; i++){
	if(i % 15 != 0){
      sum += 800;
      //cout << '!' << sum << endl;
    }
    if(i % 15 == 0){
      sum += 600;
      //cout << "!!" << sum << endl;
    }
  }
  
  cout << sum << endl;
  
}
