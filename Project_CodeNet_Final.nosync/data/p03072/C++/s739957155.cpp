#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int max = 0;
  int count = 0;
  for (int i = 0; i < N;i++){
    int H;
    cin >> H;
    if (H >= max){
      max = H;
      count++;
    }
  }
  
  cout << count;
}