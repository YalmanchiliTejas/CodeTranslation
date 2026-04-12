#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int iv[n];
  for(int i=0; i<n; ++i){
    cin >> iv[i];
  }
  int max = iv[0];
  int sum = iv[0];
  for(int i=1; i<n; ++i){
    sum += iv[i];
    while(max * (i+1) > sum){
      --max;
    }
  }
  cout << max << endl;
}

