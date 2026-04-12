#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int m = 0;
  int input;
  int count = 0;
  
  for(int i = 0; i < N; i++){
    cin >> input;
    if(m <= input){
      m = input;
      count++;
    }
  }
  
  cout << count << endl;
}