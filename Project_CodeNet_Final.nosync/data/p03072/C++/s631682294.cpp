#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n; 
  
  int count = 0;
  int* h = new int[n];
  
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    h[i] = tmp;
    bool b = true;
    for(int j=0;j<i;j++){
      b = b && h[i] >= h[j] ;
    }
    if(b || i == 0)count++;
  }
  
  
  cout << count;
  return 0;
}


