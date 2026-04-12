#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int i, h1, h2, count = 0;
  h1 = 0;
  for (i = 0; i < N; i++){
    cin >> h2;
    if(h2 >= h1){
      count++;
      h1 = h2;
    }
  }
  
  cout << count << endl;
  
  return 0;
}